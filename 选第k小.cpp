#include <stdio.h>
#include <stdlib.h>
//���ֹ鲢����
void merge(int a[],int left,int mid,int right)
{
    int i,k;
    int *tmp = (int *)malloc((right-left+1)*sizeof(int));
    int left1=left;
    int left2=mid;
    int right1=mid+1;
    int right2=right;
    for(k=0;left1<=left2 && right1<=right2;k++)
	{
        if(a[left1]<=a[right1])
		{
            tmp[k]=a[left1++];
        }
		else
		{
            tmp[k]=a[right1++];
        }
    }
    if(left1<=left2)
	{
	    for(i=left1;i<=left2;i++)
	    {
	    	tmp[k++]=a[i];
		}
    }

    if(right1<=right2)
	{
        for(i=right1;i<=right2;i++)
        {
        	tmp[k++] = a[i];
		}
    }
    for(i=0;i<right-left+1;i++)
    {
    	a[left+i]=tmp[i];
	}
    free(tmp);
    return;
}
void merge_sort(int a[],int left,int right)
{
    int mid = 0;
    if(left<right)
	{
        mid = (left+right)/2;
        merge_sort(a,left,mid);
        merge_sort(a,mid+1,right);
        merge(a,left,mid,right);
    }
    return;
}
//�����㷨 
int select(int a[],int left,int right,int k) 
{
	int n=right-left;//���������ģ��С 
	//С��5ʱֱ���ö��ֹ鲢����
	if (n<5){
		merge_sort(a,left,right-1);
		return a[left+k-1];
	}
	int i;
	int t=n/5;//ÿ���һ�飬��Ϊt�� 
	int *m = new int[t];
	for (i=0;i<t;i++) {//����λ������ 
		merge_sort(a,left+i*5,left+i*5+5-1);
		m[i] = a[left+i*5+2];
	}
	merge_sort(m,0,i-1);
	int mid=m[i/2];//����λ�������е���λ��mid
	int *a1=new int[n];
	int *a2=new int[n];
	int *a3=new int[n];
	int s1=0,s2=0,s3=0;
	for(int i=left;i<right;i++)
	{
		if(a[i]<mid)//Ԫ��С��mid����a1���� 
		{
			a1[s1++]=a[i];
		}
		else if(a[i]==mid)//Ԫ�ص���mid����a2����
		{
			a2[s2++]=a[i];
		}
		else//����Ԫ�ش�����a3����
			a3[s3++]=a[i];
	}
	if(s1>=k)//���С��mid�ĸ������ڻ����k
	{
		return select(a1,0,s1,k);
	}
	if (s1+s2>=k)//���С��mid�ĸ������ϵ���mid�ĸ������ڻ����k��
	{
		return mid;
	}
	else//������� 
		return select(a3,0,s3,k-s1-s2);
}
int main()
{
    int n,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	printf("��%dСԪ��Ϊ%d",k, select(a,0,n,k));
    return 0;
}
