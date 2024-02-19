package listaDuplamenteEncadeada;

import listaDuplamenteEncadeada.Ligacao;

public class Metodos {
	private Ligacao primeiro;
	private Ligacao ultimo;

	public Metodos(){
		primeiro = null;
		ultimo = null;
	}
	
	public boolean vazia(){
		return primeiro == null;
	}
	
	public void insereInicio(int chave) { 
		Ligacao novaLigacao = new Ligacao (chave);
		
		if(vazia())
			ultimo = novaLigacao;
		else 
			primeiro.anterior= novaLigacao;
		novaLigacao.proximo = primeiro;
		primeiro = novaLigacao;
	}
	
	public void insereFinal(int chave){
		Ligacao novaLigacao = new Ligacao(chave);
		if(vazia())
		{
			primeiro = novaLigacao;
		}else
		{
			ultimo.proximo = novaLigacao;
			novaLigacao.anterior = ultimo;
		}
		ultimo = novaLigacao;
	}
	

	public Ligacao removeInicio(){
		Ligacao temp = primeiro;
		if(primeiro.proximo == null)
			ultimo = null;
		else
		primeiro.proximo.anterior = null;
		primeiro = primeiro.proximo;
		return temp;
	}

	public Ligacao removeFinal(){
		Ligacao temp = ultimo;
		if(primeiro.proximo == null)
		primeiro = null;
		else
		ultimo.anterior.proximo = null;
		ultimo = ultimo.anterior;
		return temp;
	
	}

	public boolean inserePosicao(int chave, int dd){
		Ligacao atual = primeiro;
		while(atual.dado != chave)
		{
			atual = atual.proximo;
			if(atual == null)
			return false;
		}
		Ligacao newLigacao = new Ligacao(dd);
		if(atual==ultimo)
		{
			newLigacao.proximo = null;
			ultimo = newLigacao;
		}
		else
		{
			newLigacao.proximo = null;
			atual.proximo.anterior = newLigacao;
		}
	   newLigacao.anterior = atual;
	   atual.proximo = newLigacao;
	   return true;
	}
	
	public Ligacao pesquisaRemove(int chave){
		Ligacao atual = primeiro;
		while(atual.dado != chave){
			atual = atual.proximo;
			if(atual==null)
				return null;
		}
		if(atual==primeiro)
			primeiro = atual.proximo;
		else
			atual.proximo.anterior = atual.anterior;
		return atual;
	}

	public void imprimeContrario(){ //imprime de tras pra frente
		System.out.print("List (ultimo->primeiro): ");
		Ligacao atual = ultimo;
		while(atual != null){
			atual.linkExibicao();
			atual = atual.anterior;
		}
		System.out.println("");
	}

	
	public void imprimeOrdem() { //imprime do primeiro ao ultimo
		System.out.print("List (primeiro->ultimo): ");
		Ligacao atual = primeiro;
		while(atual != null) {
			atual.linkExibicao();
			atual = atual.proximo;
		}
		System.out.println("");
	}

}
