		************BINARY SEARCH****************************
int binary_Search(int arr[] ,int n,int x){
	int a=0 , b=n-1;
	while(a<=b){
		int k=(a+b)/2;
		if(arr[k]==x) return k+1;
		else if(arr[k]<x) a=k+1;
		else b=k-1;
	}
	return -1;
}
	*******************JUMP SEARCH******************************
int jumpSearch(int arr[], int x, int n) 
{  
    int step = sqrt(n); 
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    }  
    while (arr[prev] < x) 
    { 
        prev++;  
        if (prev == min(step, n)) 
            return -1; 
    } 
    if (arr[prev] == x) 
        return prev; 
    return -1; 
} 
