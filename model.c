/*
 * model.c
 * Bilal Ozcan
 * 18120205035
 * Game Of Life adli oyunun model.c dosyayısındaki fonksiyonlarin yazilmasi
 */

#include "gameoflife.h"
int grid[M][N] = {0}; 	/*M ve N boyutlarında 2 boyutlu bir dizi olusturur
						 *Ve butun degerlerine sifir atar.*/
						/*M and N are constants defined in gameOfLife.h*/

/**
 * initializes the grid with the chosen initial state
 */
int initGridWithBlinker(){ /*Her 10x10 alt-gride Blinker yerlestiren fonksıyon*/
	int i = 0, j = 0;
		while(i < M && j < N){ /*i M den kucuk ve j N den kucuk oldugu surece
								*icindekileri döndüren while düngüsü*/
				grid[i+4][j+5] = 1;
				grid[i+5][j+5] = 1;
				grid[i+6][j+5] = 1;
				i = i+10;
				j = j+10;
			
		}
	return 0;
}
int initGridWithGlider(){ /*Her 10x10 alt-gride Gider yerlestiren fonksıyon*/
	int i = 0, j = 0;
		while(i < M && j < N){ /*i M den kucuk ve j N den kucuk oldugu surece
								*icindekileri döndüren while düngüsü*/
				grid[i+5][j+4] = 1;
				grid[i+6][j+5] = 1;
				grid[i+6][j+6] = 1;
				grid[i+5][j+6] = 1;
				grid[i+4][j+6] = 1;
				i = i+10;
				j = j+10;
			
		}
	return 0;
}
int initGrid(int initialState){ /*initialState degerine göre Blinker veya Glider
								 *yerlestiren fonksıyon*/
	switch(initialState){
	case 1:
		initGridWithBlinker();
		return 0;
	case 2:
		initGridWithGlider();
		return 0;
	}
	

	return 0;

}

/**
 * returns the number of live neighbors of the cell
 * at position (x, y) on the grid
 */
int getNumberOfLiveNeighbors(int x, int y){ /*Verilen x ve y degerlerine gore e elamanın
											 *etrafındaki canli komsu sayısını bulan fonksiyon*/
	int neighbors = 0;
		for (int i = x-1; i <= x+1; i++){
			for(int j = y-1; j <= y+1; j++){
				if (!(i == x && j == y)){
					if((i < M) && (j < N) && (i >= 0) && (j >= 0)){
						if (grid[i][j] == 1){
							neighbors++; 
						}
					}
				}
			}
		}
	return neighbors;
}

/**
 * updates each cell by following the update rules of the game of life
 */
int updateGrid(){ /*Oyunun kurallarına göre grid dizisini bir sonraki gorunume guncelleyen fonksiyon*/
	int neighbor[M][N] = {0}; /*M ve N boyutunde 2 boyutlu bir dizi olsturup elemanlarına 0 ata
							   *Komsu sayısını tutan dizidir.*/
		
		for(int i = 0; i < M; i++){ /*Her elemanın etrafındakı canlı komsu sayisini neighbor
									 *disizine kaydeden dongu*/
			for(int j = 0; j < N; j++){
				neighbor[i][j] = getNumberOfLiveNeighbors(i, j);
			}
		}
		for(int i = 0; i < M; i++){ /*Her bir elemanı komsu sayısına bakarak kurallara göre guncelleyen
									 *dongudur.*/
			
			for(int j = 0; j < N; j++){
				if(grid[i][j] == 1){
					if(neighbor[i][j] == 1 || neighbor[i][j] == 0){
						grid[i][j] = 0;
					}
					else if(neighbor[i][j] == 2 || neighbor[i][j] == 3){
						grid[i][j] = 1;
					}
					else if(neighbor[i][j] > 3){
						grid[i][j] = 0;
					}
				}
				if(grid[i][j] == 0){
					if(neighbor[i][j] == 3){
					grid[i][j] = 1;
					}
				}
			}
		}
		
	return 0;
}

