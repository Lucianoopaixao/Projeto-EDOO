<h1 align="center">🍻 CInestesia: Sistema de Gerenciamento de Bar em C++</h1>

<p align="center">
  <strong>Relatório de Projeto – Disciplina de Estrutura de Dados e Orientação a Objetos (EDOO)</strong><br>
  Centro de Informática (UFPE)
</p>

### 👨‍🏫 Professor
**Francisco Paulo Magalhães Simões**

### 📘 Disciplina
**Estrutura de Dados e Orientação a Objetos (EDOO)**

## 🧩 1. Introdução

### 1.1 Contextualização
O projeto **"CInestesia"** consiste em um sistema de gerenciamento para um barzinho, desenvolvido integralmente na linguagem **C++**.  
Foi concebido como atividade avaliativa da disciplina de **Estrutura de Dados e Orientação a Objetos (EDOO)**, ministrada pelo professor **Francisco Paulo Magalhães Simões**.

O sistema é uma aplicação em **modo console (CLI)** que simula o funcionamento de um bar, oferecendo um **cardápio digital** e funcionalidades de **gerenciamento de pedidos**.

### 1.2 Objetivos
O objetivo principal é aplicar de forma prática os conceitos fundamentais de **Programação Orientada a Objetos (POO)**.  
O sistema implementa operações CRUD (Create, Read, Update, Delete) para gerenciar **produtos** e **pedidos de clientes**.

## ⚙️ 2. Fundamentação Teórica

Durante o desenvolvimento, foram explorados os seguintes conceitos:

- **Linguagem C++**
- **Programação Orientada a Objetos (POO)**: uso de classes, objetos, encapsulamento, construtores e destrutores.
- **Polimorfismo e Herança**:  
  As classes `Bebidas` e `Aperitivo` herdam de `Produto`, aproveitando e especializando comportamentos.
- **Gerenciamento de Memória**:  
  Utilização de alocação dinâmica (`new`) e desalocação manual (`delete`) para controle de objetos e prevenção de vazamentos.

## 🧱 3. Metodologia e Arquitetura

### 3.1 Arquitetura do Projeto
O núcleo do sistema é a classe **Barzinho**, que gerencia o cardápio e os pedidos finalizados.  
O projeto segue um modelo orientado a objetos, com herança e polimorfismo entre as classes **Produto**, **Bebidas** e **Aperitivo**.

### 3.2 Componentes Principais

#### 🏠 Barzinho (`Barzinho.h` / `Barzinho.cpp`)
- **Responsabilidade:** classe principal do sistema.  
- **Atributos:**  
  - `Produto* cardapio[100]`  
  - `Pedido* pedidos[100]`  
- **Funções:**  
  - Adicionar e listar produtos  
  - Registrar pedidos  
  - Liberar memória (destrutor “proprietário” dos objetos)

#### 🧾 Produto (`Produto.h`)
- **Classe base abstrata** para todos os itens vendáveis.  
- Define o método virtual `void mostrar()` para exibição polimórfica.

#### 🍹 Bebidas & Aperitivo (`Bebidas.h`, `Aperitivo.h`)
- **Classes derivadas** que representam tipos específicos de produtos.  
- Sobrescrevem o método `mostrar()` e definem categorias específicas.

#### 🛍️ Pedido (`Pedido.h` / `Pedido.cpp`)
- **Armazena os dados de um pedido.**  
- Contém um `Cliente` e uma lista de produtos (`Produto* produtos[50]`).  
- Implementa `adicionaProduto()`, `mostrarPedido()` e `calcularTotal()`.

#### 👤 Cliente (`Cliente.h` / `Cliente.cpp`)
- Representa o cliente (atributo principal: nome).

#### 🖥️ main.cpp
- **Ponto de entrada do programa.**  
- Popula o bar com produtos, controla o menu principal e registra os pedidos.

## 📊 4. Resultados e Discussão

### 4.1 Apresentação do Sistema

#### 1️⃣ Tela inicial – Cadastro do cliente
<img width="419" height="398" alt="Tela inicial" src="https://github.com/user-attachments/assets/f436e27a-3765-4e39-a1f1-208d64bea417" />

#### 2️⃣ Segunda tela – Cardápio
<img width="371" height="367" alt="Cardápio" src="https://github.com/user-attachments/assets/192b4b3b-9219-423d-ad7a-e414882ce4b4" />

#### 3️⃣ Terceira tela – Pedido adicionado
<img width="350" height="355" alt="Pedido adicionado" src="https://github.com/user-attachments/assets/972d0cc7-d9d5-4ad8-a114-c02816bd7db9" />

#### 4️⃣ Tela final – Pedido finalizado
<img width="409" height="334" alt="Pedido finalizado" src="https://github.com/user-attachments/assets/32f3ce7e-2903-4d2e-a2b5-5024976c741c" />


## 🗂️ 5. Estrutura de Arquivos

Barzinho_C-/
├── .qtcreator/
│ └── CMakeLists.txt.user
├── .gitignore
├── Aperitivo.h
├── Barzinho.cpp
├── Barzinho.h
├── barzinho.db
├── barzinhoterminal.exe
├── Bebidas.h
├── Cliente.cpp
├── Cliente.h
├── CMakeLists.txt
├── main.cpp
├── mainterminal.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── Pedido.cpp
├── Pedido.h
├── Produto.h
├── README.md
├── sqlite3.c
├── sqlite3.h
├── sqlite3.o
├── telacardapio.cpp
├── telacardapio.h
├── telacardapio.ui
├── telafinal.cpp
├── telafinal.h
└── telafinal.ui

## 🧠 6. Conclusão

O projeto **CInestesia** possibilitou a aplicação prática dos conceitos de **Estrutura de Dados** e **Programação Orientada a Objetos**.  
A utilização de **herança**, **polimorfismo** e **gerenciamento manual de memória** foi essencial para construir um sistema funcional e modular.

Os objetivos propostos foram atingidos, resultando em uma aplicação que implementa operações CRUD para um ambiente de bar e proporciona uma boa experiência de uso no terminal.

## 🧰 7. Instruções de Compilação

Há duas formas de compilar e executar o projeto:

### 💻 Via Qt Creator (com interface gráfica)
- Abra o projeto pelo arquivo `CMakeLists.txt` e execute.

### 🖥️ Via Terminal (modo console)
- Compile e execute o arquivo:
  ```bash
  ./barzinhoterminal.exe
