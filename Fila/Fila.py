class Fila:
    def __init__(self):
        self.inicio = 0
        self.fim = -1
        self.itens = [0] * 5

def mostrar_menu():
    print("------------------- MENU -------------------\n")
    print("[1] - Inserir um elemento na Fila")
    print("[2] - Remover um elemento da Fila")
    print("[3] - Verificar condição da Fila")
    print("[0] - Encerrar o Programa\n")
    print("--------------------------------------------\n")
    opc = int(input("DIGITE SUA ESCOLHA: "))
    print()
    return opc

def inserir_fila(e, f):
    f.fim += 1
    f.itens[f.fim] = e
    print("\nElemento", e, "foi inserido na Fila.\n\n\n")

def remover_fila(f):
    if f.fim == -1:
        print("!!! A Fila ESTA VAZIA !!!\n")
        print("Não é possível remover mais elementos.\n\n\n")
    else:
        elemento_removido = f.itens[f.inicio]
        for i in range(1, f.fim + 1):
            f.itens[i - 1] = f.itens[i]
        f.fim -= 1
        print("O elemento", elemento_removido, "foi removido da Fila.\n\n\n")

def verificar_condicao_fila(f):
    if f.fim == 4:
        print("!!! A FILA ESTA CHEIA !!!\n")
        print("FILA =", end=" ")
        for i in range(f.fim + 1):
            print("- [", f.itens[i], "]", end=" ")
        print("\n\n\n")
    elif f.fim == -1:
        print("!!! A FILA ESTA VAZIA !!!\n\n\n")
    elif f.fim != -1:
        print("A sua Fila atual é:\n")
        print("FILA =", end=" ")
        for i in range(f.fim + 1):
            print("- [", f.itens[i], "]", end=" ")
        print("\n\n\n")

f = Fila()

while True:
    opc = mostrar_menu()
    
    if opc >= 4 or opc < 0:
        print("OPCAO INVALIDA - Escolha uma nova opcao.\n\n")
    
    if opc == 1:
        print("----------------- ENTRADA -----------------\n")
        if f.fim != 4:
            elemento = int(input("Digite um elemento para entrar na Fila: "))
            inserir_fila(elemento, f)
        else:
            print("!!! A Fila ESTA CHEIA !!!\n\nNão é possível inserir mais elementos.\n\n\n")

    if opc == 2:
        print("----------------- REMOCAO -----------------\n")
        
        remover_fila(f)
    
    if opc == 3:
        print("----------------- CONDICAO -----------------\n")
        
        verificar_condicao_fila(f)
    
    if opc == 0:
        print("------------------ SAIDA ------------------\n")
        print("Encerrando o Programa...            =)\n")
        input("-------------------------------------------\n\n")
        break
