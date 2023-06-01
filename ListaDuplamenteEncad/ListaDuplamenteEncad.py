class ListaEncad:
    def __init__ (self):
        self.anterior = None
        self.posicao = 0
        self.elemento = 0
        self.proximo = None

ponteiroInicial = ListaEncad()
ponteiroAtual = ponteiroInicial

while True:
    print("-------------- ENTRADA --------------\n")
    ponteiroAtual.posicao = int(input("Entre com a posicao do Elemento: "))
    ponteiroAtual.elemento = int(input("Entre com o valor da posicao [{}]: ".format(ponteiroAtual.posicao)))
    resp = int(input("\nDeseja Continuar?\n\n[1] - Sim\n[2] - Nao\n\nSUA ESCOLHA: "))
    print()

    if resp == 1:
        ponteiroAtual.proximo = ListaEncad()
        ponteiroAtual.proximo.anterior = ponteiroAtual.posicao
        ponteiroAtual = ponteiroAtual.proximo
    else:
        break

while ponteiroInicial is not None:
    print("Posicao Anterior: ", ponteiroInicial.anterior)
    print("POSICAO ATUAL: ", ponteiroInicial.posicao)
    print("ELEMENTO SALVO: ", ponteiroInicial.elemento)

    if ponteiroInicial.proximo is None:
        print("Posicao Proximo: None")
    else:
        print("Posicao Proximo: ", ponteiroInicial.proximo.posicao)

    print()
    ponteiroInicial = ponteiroInicial.proximo

