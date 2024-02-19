package bubbleSort;

public class ArrayBub {
	private long[] a;
	private int nElems;
	
	public ArrayBub(int max)
	{
		a = new long[max];
		nElems = 0;
	}
	
	public void insert(long value)
	{
		a[nElems] = value;
		nElems++;
	}
	
	public void imprime()
	{
		for(int j=0; j<nElems; j++)
			System.out.print(a[j] + " ");
		System.out.println("");
	}
	
	public void BubbleSort()
	{
		int out, in;
		for(out=nElems-1; out>1; out--)
			for(in=0; in<out; in++)
				if(a[in] > a[in+1])
				{
					troca(in, in+1);
				}
	}
	private void troca(int um, int dois)
	{
		long temp = a[um];
		a[um] = a[dois];
		a[dois] = temp;
	}

}
