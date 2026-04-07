class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));//初始化二维矩阵，第一个参数为个数
        int loop=n/2; //循环次数
        int mid=n/2;
        int startx=0,starty=0; //循环开始的地方
        int i=0,j=0; //循环遍历
        int offset=1;
        int num=1;

        while(loop--)
        {
            i=startx;
            j=starty;
            //左闭右开,推出条件j=n-offset
            for(j;j<n-offset;j++)
            {
                res[i][j]=num;
                num++;
            }
            for(i;i<n-offset;i++)
            {
                res[i][j]=num;
                num++;
            }
            for(j;j>starty;j--)
            {
                res[i][j]=num;
                num++;
            }
            for(i;i>startx;i--)
            {
                res[i][j]=num;
                num++;
            }
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;
             // offset 控制每一圈里每一条边遍历的长度
            offset++;
        }
        if(n%2!=0)
        {
            res[mid][mid]=num;
        }
        return res;
        
    }
};