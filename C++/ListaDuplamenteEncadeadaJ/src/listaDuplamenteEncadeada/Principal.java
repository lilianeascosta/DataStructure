package listaDuplamenteEncadeada;

import java.util.Scanner;

import listaDuplamenteEncadeada.Metodos;

public class Principal {
	
	public static void main(String[] args)
	{
		Metodos lista = new Metodos();
		Scanner input = new Scanner(System.in);
		
		int opcMenu, opcDnv;
		do {
			lista.imprimeOrdem();
			
			System.out.println("1. Insere Inicio");
			System.out.println("2. Insere Final");
			System.out.println("3. Insere Posicao");
			System.out.println("4. Remove Inicio");
			System.out.println("5. Remove Final");
			System.out.println("6. Remove Elemento");
			System.out.println("7. Imprime da Frente pra trás");
			System.out.println("8. Imprime de trás pra frente");
			System.out.println("9. Sair do Programa");
			System.out.print("Informe sua opção: ");
			opcMenu = input.nextInt();
			
			int dado, pos;
			
			switch(opcMenu) {
			case 1:
				System.out.println("Informe a chave: ");
				dado = input.nextInt();
				lista.insereInicio(dado);
				break;
			case 2:
				System.out.println("Informe a chave: ");
				dado = input.nextInt();
				lista.insereFinal(dado);
				break;
			case 3:
				System.out.println("Informe a chave: ");
				dado = input.nextInt();
				System.out.println("Informe a posição: ");
				pos = input.nextInt();
				lista.inserePosicao(dado, pos);
				break;
			case 4: 
				lista.removeInicio();
				break;
			case 5: 
				lista.removeFinal();
				break;
			case 6:
				System.out.println("Informe a chave: ");
				dado = input.nextInt();
				lista.pesquisaRemove(dado);
				break;
			case 7: 
				lista.imprimeOrdem();
				break;
			case 8: 
				lista.imprimeContrario();
				break;
			case 9: 
				System.exit(0);
				break;
			}
			System.out.print("De novo? (1: s/ 2: n): ");
			opcDnv = input.nextInt();
		} while(opcDnv == 1);
		input.close();
	}
}
