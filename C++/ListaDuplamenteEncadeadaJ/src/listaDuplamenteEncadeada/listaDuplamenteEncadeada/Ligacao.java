package listaDuplamenteEncadeada;

import listaDuplamenteEncadeada.Ligacao;

public class Ligacao {
	public int dado;
	public Ligacao proximo;
	public Ligacao anterior;
	
	public Ligacao(int d){
		dado = d;
	}
	
	public void linkExibicao() {
		System.out.print(dado + " ");
	}
}
