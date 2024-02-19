package bubbleSortString;

public class ArrayBubString {
	private String[] a;
	private int nElems;
	
	public ArrayBubString(int max)
	{
		a = new String[max];
		nElems = 0;
	}
	
	public void insert(String value)
	{
		a[nElems] = value;
		nElems++;
	}
	
	public void imprime()
	{
		for(int j=0; j<nElems; j++)
			System.out.println("a[j]" + a[j]);
		System.out.println("");
	}
	
	public void BubbleSort()
	{
		int out, in;
		for(out=nElems-1; out>0; out--) //for vai de 10 até 1
			for(in=0; in<out; in++)
				if((a[in].compareTo(a[in+1])) > 0) 
					troca(in, in+1);
	}
	private void troca(int um, int dois)
	{
		String aux = a[um];
		a[um] = a[dois];
		a[dois] = aux;
	}

}
