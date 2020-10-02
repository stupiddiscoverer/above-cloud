// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hero {
	char name[12] = "";
	char coin[4] = "0费";
	char fetter1[14] = "";
	char fetter2[14] = "";
	char fetter3[14] = "";
};
struct fetnum {
	char fetter[14] = "";
	char n1=0, n2=0, n3=0, n4=0;
};
struct fetCount {
	char fetter[14] = "";
	int count = 0;
};

void getData(hero a[],fetnum b[]);
hero he[58];
fetnum fn[26];
void C(int n, int i,int j);
void D(int j);
bool compareStr(char a[], char b[]);
void writeTxt(int fets, int j, int x);

hero combination[9];
fetCount nFetter[24];

int main()
{
	getData(he, fn);
	printf("got data(^_^)\n");
	for (int x = 0; x < 26; x++) {
		printf("%s: %d, %d, %d, %d\n",fn[x].fetter, fn[x].n1,fn[x].n2,fn[x].n3,fn[x].n4);
	}
	for(int i=7;i<10;i++)
		C(i, 0,i);
	return 0;
}
bool compareStr(char a[], char b[]) {
	if (strlen(a) != strlen(b))
		return false;
	for (int x = 0; x < strlen(a); x++)
		if (a[x] != b[x])
			return false;
	return true;
}
void C(int n, int i, int j) {
	if (n < 1) {
		D(j);
		return;
	}
	while (i < 58) {
		combination[j - n] = he[i];
		i++;
		C(n - 1, i,j);
		hero jiliguala;
		combination[j - n] = jiliguala;
	}
}
void D(int j) {
	fetCount guala;
	for (int x = 0; x < 24; x++) {
		nFetter[x] = guala;
	}
	int fets = 0, sfet = 0;
	//统计nFetter
	for (int x = 0; x < j; x++) {  //9个英雄
		int y = 0;
		bool no1 = true, no2 = true, no3 = true; //英雄的3个羁绊是否未录入
		while (nFetter[y].count!=0) { //9个人的羁绊统计数组
			if (compareStr(nFetter[y].fetter, combination[x].fetter1)) {
				nFetter[y].count++;
				no1 = false;
				y++;
				continue;
			}
			if (compareStr(nFetter[y].fetter, combination[x].fetter2)) {
				nFetter[y].count++;
				no2 = false;
				y++;
				continue;
			}
			if (compareStr(nFetter[y].fetter, combination[x].fetter3)) {
				nFetter[y].count++;
				no3 = false;
			}
			y++;
		}
		if (no1 == true) {
			for (int a = 0; a<14; a++)
				nFetter[y].fetter[a] = combination[x].fetter1[a];
			nFetter[y].count = 1;
			y++;
		}
		if (no2 == true) {
			for (int a = 0; a<14; a++)
				nFetter[y].fetter[a] = combination[x].fetter2[a];
			nFetter[y].count = 1;
			y++;
		}
		if (no3 == true) {
			if (combination[x].fetter3[0] == 0 &&
				combination[x].fetter3[1] == 0) {
				continue;
			}
			for (int a = 0; a < 14; a++) {
				nFetter[y].fetter[a] = combination[x].fetter3[a];
			}
			nFetter[y].count = 1;
			y++;
		}
	}
	//计算有效羁绊和总羁绊
	for (int x = 0; nFetter[x].count; x++) {
		fets += nFetter[x].count;
		for (int y = 0; y < 26; y++) {
			if (compareStr(nFetter[x].fetter, fn[y].fetter)) {
				if (nFetter[x].count >= fn[y].n4 && fn[y].n4) {
					sfet += fn[y].n4;
					break;
				}
				if (nFetter[x].count >= fn[y].n3 && fn[y].n3) {
					sfet += fn[y].n3;
					break;
				}
				if (nFetter[x].count >= fn[y].n2 && fn[y].n2) {
					sfet += fn[y].n2;
					break;
				}
				if (nFetter[x].count >= fn[y].n1)
					sfet += fn[y].n1;
				break;
			}
		}
	}
	if (fets == sfet)
		writeTxt(fets, j, -1);
	if (fets == sfet + 1) {
		int godChoose = -1;
		for (int x = 0; nFetter[x].count && godChoose < 0; x++) {
			for (int y = 0; y < 26; y++) {
				if (compareStr(nFetter[x].fetter, fn[y].fetter)) {
					int p = nFetter[x].count;
					if (p == fn[y].n1 || p == fn[y].n2 || p == fn[y].n3 ||
						p == fn[y].n4)
						break;
					p++;
					if (p == fn[y].n1 || p == fn[y].n2 || p == fn[y].n3 ||
						p == fn[y].n4) {
						nFetter[x].count++;
						fets++;
						printf(nFetter[x].fetter);
						godChoose = x;
						printf("--天选\n");
					}
					else
						return;
					break;
				}
			}
		}
		writeTxt(fets, j, godChoose);
	}
}
void writeTxt(int fets, int j, int godChoose) {
	printf("***%d\n", godChoose);
	FILE* fp;
	fopen_s(&fp, "c:/users/children/desktop/God789.txt", "a");
	if (godChoose > 0) {
		fputs("天选--", fp);
		fputs(nFetter[godChoose].fetter, fp);
		fputs(" * ", fp);
	}
		
	for (int x = 0; nFetter[x].count; x++) {
		fputs(nFetter[x].fetter, fp);
		fputc(' ', fp);
		fputc(nFetter[x].count + 48, fp);
		fputs("  ", fp);
	}
	fputc('\n', fp);
	fputs("羁绊数：", fp);
	fputc('1', fp);
	fputc(char(fets - 10 + 48), fp);
	fputc(' ', fp);
	for (int a = 0; a < j; a++) {
		fputs(combination[a].name, fp);
		fputc(' ', fp);
	}
	fputc('\n', fp);
	fclose(fp);
}
void getData(hero he[],fetnum fn[]) {
	char line[60]; //每行不超过60字节，即30个汉字
	FILE* fp;
	fopen_s(&fp, "c:/users/children/desktop/zuizhong.txt", "r");
	int i = 0;
	while (fgets(line, 60, fp) != NULL) {
		int j = 0, k = 0, l = 0;
		while (line[j] != '\n') {
			if (line[j] == ' ' || line[j] == '+') {
				k++;
				j++;
				l = 0;
				continue;
			}
			if (k == 0)
				he[i].name[l] = line[j];
			if (k == 1)
				he[i].coin[l] = line[j];
			if (k == 2)
				he[i].fetter1[l] = line[j];
			if (k == 3)
				he[i].fetter2[l] = line[j];
			if (k == 4)
				he[i].fetter3[l] = line[j];
			l++;
			j++;
		}
		i++;
	}
	fclose(fp);
	fopen_s(&fp, "c:/users/children/desktop/shuliang.txt", "r");
	i = 0;
	while (fgets(line, 60, fp) != NULL) {
		int j = 0, k = 0, l = 0;
		while (line[j] != '\n') {
			if (line[j] == ' ') {
				k++;
				j++;
				l = 0;
				continue;
			}
			if (k == 0)
				fn[i].fetter[l] = line[j];
			if (k == 1)
				fn[i].n1 = line[j]-48;
			if (k == 2)
				fn[i].n2 = line[j]-48;
			if (k == 3)
				fn[i].n3 = line[j]-48;
			if (k == 4)
				fn[i].n4 = line[j]-48;
			j++;
			l++;
		}
		i++;
	}
	fclose(fp);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
