class Pilha:
    def __init__(self):
        self.topo = -1
        self.itens = [0] * 5

def mostrar_menu():
    print("------------------- MENU -------------------\n")
    print("[1] - Inserir um elemento na Pilha")
    print("[2] - Remover um elemento da Pilha")
    print("[3] - Verificar condição da Pilha")
    print("[0] - Encerrar o Programa\n")
    print("--------------------------------------------\n")
    opc = int(input("DIGITE SUA ESCOLHA: "))
    print()
    return opc

def inserir_pilha(e, p):
    p.topo += 1
    p.itens[p.topo] = e
    print("\nElemento", e, "foi inserido na pilha.\n\n\n")

def remover_pilha(p):
    if p.topo == -1:
        print("!!! A PILHA ESTA VAZIA !!!\n")
        print("Não é possível remover mais elementos.\n\n\n")
    else:
        elemento_removido = p.itens[p.topo]
        p.topo -= 1
        print("O elemento", elemento_removido, "foi removido da pilha.\n\n\n")

def verificar_condicao_pilha(p):
    if p.topo == 4:
        print("!!! A PILHA ESTA CHEIA !!!\n")
        print("PILHA =", end=" ")
        for i in range(p.topo + 1):
            print("- [", p.itens[i], "]", end=" ")
        print("\n\n\n")
    elif p.topo == -1:
        print("!!! A PILHA ESTA VAZIA !!!\n\n\n")
    elif p.topo != -1:
        print("A sua pilha atual é:\n")
        print("PILHA =", end=" ")
        for i in range(p.topo + 1):
            print("- [", p.itens[i], "]", end=" ")
        print("\n\n\n")

p = Pilha()

while True:
    opc = mostrar_menu()
    
    if opc >= 4 or opc < 0:
        print("OPCAO INVALIDA - Escolha uma nova opcao.\n\n")
    
    if opc == 1:
        print("----------------- ENTRADA -----------------\n")
        if p.topo != 4:
            elemento = int(input("Digite um elemento para entrar na pilha: "))
            inserir_pilha(elemento, p)
        else:
            print("!!! A PILHA ESTA CHEIA !!!\n\nNão é possível inserir mais elementos.\n\n\n")

    if opc == 2:
        print("----------------- REMOCAO -----------------\n")
        
        remover_pilha(p)
    
    if opc == 3:
        print("----------------- CONDICAO -----------------\n")
        
        verificar_condicao_pilha(p)
    
    if opc == 0:
        print("------------------ SAIDA ------------------\n")
        print("Encerrando o Programa...            =)\n")
        input("-------------------------------------------\n\n")
        break
