package bubbleSortString;

import bubbleSortString.ArrayBubString;

public class BubbleSortString {
	public static void main(String[] args)
	{
		int tamMAX = 100;
		ArrayBubString arr;
		arr = new ArrayBubString(tamMAX);
		
		arr.insert("Jessica");
		arr.insert("Ianca");
		arr.insert("Haila");
		arr.insert("Gabriel");
		arr.insert("Fabio");
		arr.insert("Eliana");
		arr.insert("Daniel");
		arr.insert("Carol");
		arr.insert("Alessandro");
		arr.insert("Alessandra");
		
		arr.imprime();
		
		arr.BubbleSort();
		
		arr.imprime();
	}

}
