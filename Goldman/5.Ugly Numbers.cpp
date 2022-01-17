ull getNthUglyNo(int n) {
	    // code here
	    ull arr[n];
	    arr[0] = 1;
	    int i2=0,i3=0,i5=0;
	    for(int i=1;i<n;i++){
	        ull num1 = arr[i2]*2;
	        ull num2 = arr[i3]*3;
	        ull num3 = arr[i5]*5;
	        
	        if(num1<=num2 && num1<=num3)
	            arr[i] = num1, i2++;
	        if(num2<=num1 && num2<=num3)
	            arr[i] = num2, i3++;
	        if(num3<=num1 && num3<=num2)
	            arr[i] = num3, i5++;
	    }
	    return arr[n-1];
	}