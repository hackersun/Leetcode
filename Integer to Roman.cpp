class Solution {
public:
void dealWithString(string& sRoman, char* symbol, int bitnum)
{
	if(bitnum <= 3)
		sRoman.append(bitnum, *symbol);
	else if(bitnum <= 8)
	{
		int repeat = bitnum - 5;
		if(repeat < 0) sRoman.append(0-repeat, *symbol);
		sRoman.append(1, *(symbol+1));
		if(repeat > 0) 	sRoman.append(repeat, *symbol);
	}else if(bitnum == 9){
		sRoman.append(1, *symbol);
		sRoman.append(1, *(symbol+2));
	}
}

string intToRoman(int num) {
        char symbol[9] = {'I','V','X','L','C','D','M'}; 
		string sRoman = "";
		int scale = 1000;
		int step = 6;
		while(num)
		{
			int bitnum = num / scale;
			dealWithString(sRoman, symbol+step, bitnum);
			num %= scale;
			scale /= 10;
			step -= 2;
		}
		return sRoman;
    }
};