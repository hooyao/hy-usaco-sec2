/*
ID: hooyao1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <algorithm>

using namespace std;


int* rotate_90(int* in, int radius){
	int* out = new int[radius*radius];
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			out[j*radius+radius-i-1]=in[i*radius+j];
		}
	}
	return out;
}

bool compMatrix(int* a, int* b,int radius){
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			if(a[i*radius+j]!=b[i*radius+j])
				return false;
		}
	}
	return true;
}

int main() {
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");
	int radius = 0;
	fin>>radius;

	int* src = new int[radius*radius];
	int* trg = new int[radius*radius];
	
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			char tmp;
			fin>>tmp;
			src[i*radius+j] = tmp=='@'?0:1;
		}
	}
	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			char tmp;
			fin>>tmp;
			trg[i*radius+j] = tmp=='@'?0:1;
		}
	}

	for (int i=0;i<radius;i++)
	{
		for (int j=0;j<radius;j++)
		{
			printf("%d",trg[i*radius+j]);
		}
		printf("\n");
	}
	int* out = rotate_90(src,radius);

	printf("%d",compMatrix(trg,out,radius));
	//number

	
	//while(std::getline(fin,line)){
	//	std::transform(line.begin(), line.end(),line.begin(), ::toupper);
	//	for(int i=0;i<line.length();i++){
	//		
	//	}
	//}
	/*string comet;
	string group;
	if(!std::getline(fin,comet))
		return 0;
	if(!std::getline(fin,group))
		return 0;
	int cometCode =1, groupCode = 1;
	std::transform(comet.begin(), comet.end(),comet.begin(), ::toupper);
	for(int i=0;i<comet.length();i++){
		char ch = comet[i];
		int sym = ch&0x00FF-64;
		cometCode = cometCode*sym;
	}
	std::transform(group.begin(), group.end(),group.begin(), ::toupper);
	for(int i=0;i<group.length();i++){
		char ch = group[i];
		int sym = ch&0x00FF-64;
		groupCode = groupCode*sym;
	}

	fout<<(groupCode%47==cometCode%47?"GO":"STAY")<<endl;*/
	return 0;
}

