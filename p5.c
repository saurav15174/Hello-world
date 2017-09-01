        #include <stdio.h>
        #include <stdlib.h>
         
         
         
        int main()
        {
        	int t;
        	scanf("%d",&t);
        	int i;
        	for (i = 0; i < t; ++i)
        	{
        		int n,k;
        		scanf("%d",&n);
        		scanf("%d",&k);
        		int *arr[n];
        		int* s=(int*)malloc(n*sizeof(int));
        		int j;
        		for (j = 0; j < n; ++j)
        		{
        			int l;
        			scanf("%d",&l);
        			s[j]=l;
        			arr[j]=(int*)malloc(l*sizeof(int));
        			int p;
        			for (p = 0; p < l; ++p)
        			{
        				scanf("%d",&arr[j][p]);
        			}
        		}
        		int pair=0;
        		int p;
        		for (j = 0; j < n; ++j)
        		{
        			for (p = j+1; p < n; ++p)
        			{
        				int b[k+1];
        				int x;
        				for (x = 1; x <= k; ++x)
        				{
        					b[x]=x;
        				}
        				int count=0;
        				int n1=s[j];
        				int n2=s[p];
        				int l=0,m=0;
        				while(l<n1 && m<n2)
        				{
        					if(arr[j][l]!=arr[p][m] && arr[j][l]==b[arr[j][l]] && arr[p][m]==b[arr[p][m]])
        					{ 
        						count+=2;
        						b[arr[j][l]]=-1;
        						b[arr[p][m]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					else if(arr[j][l]!=arr[p][m] && arr[j][l]==b[arr[j][l]])
        					{ 
        						count++;
        						b[arr[j][l]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					else if(arr[j][l]!=arr[p][m] && arr[p][m]==b[arr[p][m]])
        					{ 
        						count++;
        						b[arr[p][m]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					else if (arr[j][l]==arr[p][m] && arr[j][l]==b[arr[j][l]])
        					{
        						count++;
        						b[arr[j][l]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					l++;
        					m++;
        				}
        				while(l<n1)
        				{
        					if (arr[j][l]==b[arr[j][l]])
        					{
        						count++;
        						b[arr[j][l]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					l++;
        				}
        				while(m<n2)
        				{
        					if (arr[p][m]==b[arr[p][m]])
        					{
        						count++;
        						b[arr[p][m]]=-1;
        						if (count==k)
        						{
        							break;
        						}
        					}
        					m++;
        				}
        				if (count==k)
        				{
        					pair++;
        				}
        			}
        		}
        		printf("%d\n",pair);
        	}
        	return 0;
        }  