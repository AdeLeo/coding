//length为牛客系统规定字符串输出的最大长度，固定为一个常数
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL)
            return ;
        
		int i = 0;
        int oldlen = 0;
        int spaceNum = 0;

        for(i = 0, oldlen = 0, spaceNum = 0 ; str[i] != '\0'; i++)
        {
            oldlen++;
            if(str[i] == ' ')
                spaceNum++;
        }

        int newlen = oldlen + spaceNum * 2;
        
        if(newlen > length)
            return;
        
        int p2 = newlen;
        int p1 = oldlen;
        char tmp[newlen+1];
        
        for(i = 0; i < newlen + 1; i++)
            tmp[i] = 0;

        for(p1 = oldlen, p2 = newlen; p1 >= 0 && p2 >= 0; )
        {
            if(str[p1] != ' ')
            {
                tmp[p2--] = str[p1--];
            }

            else
            {
                p1--;
                tmp[p2--] = '0';
                tmp[p2--] = '2';
                tmp[p2--] = '%';
            }
        }
        
        for(i = 0; i < newlen+1; i++)
        {
            str[i] = tmp[i];
        }
	}
};