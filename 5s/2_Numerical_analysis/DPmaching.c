#include <stdio.h>
#include <stdlib.h>

#define N 160 //1行の最大文字数おおよそ
#define i 150 //フレーム数の上限
#define j 15  //dimention

int main(void) {
	FILE *fp,*fp2;
	int frame_tpl[100] = {}; 			//テンプレートのフレーム数
	int frame_miti[100] = {}; 			//未知数のフレーム数
	int k=0, x=0, y=0; 						//k:フレーム数取得で使ってる x:データの読み取り
	double data_tpl[100][i][j] = {};
	double data_miti[100][i][j] = {};

	for(int a=1,z=0; a<=100,z<100; a++,z++){		//i=テキスト番号
		char filename[100];
		sprintf(filename, "city011/city011_%03d.txt", a);
		char str[N], chr[] = {};

		fp = fopen(filename, "r");
		if(fp == NULL) {
			printf("%s file not open!\n", filename);
			return -1;
		}

		for(int t=0; t<3; t++){			//t=行数:3行目まで読み込みフレーム数取得
			(fgets(str, N, fp) != NULL);
			if(t==2){
				frame_tpl[k] = atoi(str);
				//printf("%d\n", frame_tpl[k]);		//char型をint型に変更
			}
		}
		k++;

		for(int t=0; t<frame_tpl[x]; t++){ //t:行数:4行目から読み込みデータ格納
			for(int c=0; c<15; c++){        //c:dimention数
				fscanf(fp, "%s", &chr);
				data_tpl[z][t][c] = atof(chr);
			}
		}
		x++;
	}
  k=0;
	fclose(fp);
	printf("%lf\n", data_tpl[0][0][0]);

	for(int a=1,z=0; a<=100,z<100; a++,z++){		//i=テキスト番号
		char filename[100];
		sprintf(filename, "city012/city012_%03d.txt", a);
		char str[N], chr[]={};

		fp2 = fopen(filename, "r");
		if(fp2 == NULL) {
			printf("%s file not open!\n", filename);
			return -1;
		}

		for(int t=0; t<3; t++){			//t=行数
			(fgets(str, N, fp2) != NULL);
			if(t==2){
				frame_miti[k] = atoi(str);
				//printf("%d\n", frame_miti[k]);		//char型をint型に変更
			}
		}
		k++;


		for(int t=0; t<frame_miti[y]; t++){ //t:行数:4行目から読み込みデータ格納
			for(int c=0; c<15; c++){        //c:dimention数
				fscanf(fp2, "%s", &chr);
				data_miti[z][t][c] = atof(chr);
			}
		}
		y++;
	}
	fclose(fp2);
	printf("%lf\n", data_miti[0][0][0]);

	return 0;
}
