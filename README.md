CInestesia: Sistema de Gerenciamento de Bar em C++

Relatório de Projeto da Disciplina de Estrutura de Dados e Orientação a Objetos (EDOO) – Centro de Informática (UFPE).

Disciplina: Estrutura de Dados e Orientação a Objetos (EDOO)

Professor: Francisco Paulo Magalhães Simões

1. Introdução

1.1. Contextualização

Este documento detalha o projeto "Cinestesia", um sistema de gerenciamento para um barzinho, desenvolvido integralmente na linguagem C++. O projeto foi concebido como atividade avaliativa para a disciplina de Estrutura de Dados e Orientação a Objetos (EDOO), ministrada pelo professor Francisco Paulo Magalhães Simões.

O "Cinestesia" é uma aplicação em modo console (CLI) que simula um ambiente de bar, oferecendo um cardápio digital e funcionalidades de gerenciamento de pedidos.

1.2. Objetivos

O objetivo central do projeto é aplicar de forma prática os conceitos fundamentais de Programação Orientada a Objetos (POO). O sistema implementa as operações básicas de gerenciamento no estilo CRUD (Create, Read, Update, Delete) para os produtos do cardápio e para os pedidos dos clientes.


2. Fundamentação Teórica

Para o desenvolvimento do projeto, foram utilizados e explorados os seguintes conceitos lecionados na disciplina:

· Linguagem C++

· Programação Orientada a Objetos (POO): O projeto foi estruturado utilizando classes, objetos, encapsulamento (atributos privados/públicos), construtores e destrutores para modelar as entidades do sistema (Barzinho, Produto, Pedido, Cliente).

· Polimorfismo e Herança: Utilizada para criar uma hierarquia de produtos. As classes Bebidas e Aperitivo herdam da classe base Produto, permitindo a reutilização de código e a especialização de tipos.

· Gerenciamento de Memória: Foi feito o uso de alocação dinâmica (operador new) para a criação de objetos (Produtos, Pedidos) e o gerenciamento manual da desalocação (operador delete) nos destrutores das classes "proprietárias" (como Barzinho).


3. Metodologia e Arquitetura

Esta seção descreve a arquitetura do software, o design das classes e as ferramentas utilizadas.

3.1. Arquitetura do Projeto

O projeto implementa um sistema simples de pedidos para um bar (Barzinho), escrito em C++ e orientado a objetos. O núcleo é a classe Barzinho, que atua como a fachada do sistema, mantendo o cardápio (produtos) e armazenando os pedidos finalizados.

Os produtos são modelados por uma hierarquia, onde Bebidas e Aperitivo são subclasses de Produto. A aplicação é de console (CLI) e utiliza extensivamente herança e polimorfismo para a exibição dos itens do cardápio e dos pedidos.

3.2. Descrição dos Componentes Principais

Abaixo detalhamos a responsabilidade de cada classe no sistema:

· Barzinho (Barzinho.h / Barzinho.cpp)

o Responsabilidade: Classe principal que orquestra o sistema.

o Atributos: Mantém um cardápio (Produto* cardapio[100]) e uma lista de pedidos finalizados (Pedido* pedidos[100]).

o Métodos: Responsável por adicionar produtos ao cardápio, listar produtos por categoria e armazenar novos pedidos.

o Gerenciamento de Memória: O destrutor da classe libera (usando delete) os objetos de cardapio e pedidos. Portanto, Barzinho é a classe "proprietária" (owner) desses objetos.

· Produto (Produto.h)

o Responsabilidade: Classe base abstrata para todos os itens vendáveis.

o Atributos: nome, preco e categoria.

o Métodos: Define o método virtual void mostrar() para permitir polimorfismo na exibição dos dados.

· Bebidas e Aperitivo (Bebidas.h, Aperitivo.h)

o Responsabilidade: Classes derivadas que representam tipos específicos de produtos.

o Métodos: Sobrescrevem (override) o método mostrar() para exibir seus atributos específicos e definem a categoria apropriada no construtor.

· Pedido (Pedido.h / Pedido.cpp)

o Responsabilidade: Armazena os dados de um único pedido.

o Atributos: Contém um objeto Cliente (por valor) e um array de ponteiros Produto* produtos[50].

o Métodos: adicionaProduto, mostrarpedido, calcularTotal.

o Gerenciamento de Memória: A classe não deleta os ponteiros Produto* que recebe, pois eles são apenas referências a produtos que já existem no cardápio (gerenciados pelo Barzinho).

· Cliente (Cliente.h / Cliente.cpp)

o Responsabilidade: Classe simples para representar o cliente (contém apenas nome).

· main.cpp

o Responsabilidade: Ponto de entrada da aplicação (função main).

o Funções: Popula o Barzinho com produtos iniciais (alocados com new), controla o menu principal, lê as interações do usuário, cria pedidos (new Pedido(...)), adiciona produtos a esses pedidos (referenciando ponteiros do cardápio) e, ao final, registra os pedidos no Barzinho.


4. Resultados e Discussão

Nesta seção, apresentamos o funcionamento do programa através de capturas de tela e detalhamos os testes realizados.

4.1. Apresentação do Sistema


1. Tela inicial – Cadastro do cliente.
   <img width="419" height="398" alt="image" src="https://github.com/user-attachments/assets/f436e27a-3765-4e39-a1f1-208d64bea417" />


3. Segunda tela - Cardápio.
    <img width="371" height="367" alt="image" src="https://github.com/user-attachments/assets/192b4b3b-9219-423d-ad7a-e414882ce4b4" />


4. Terceira tela – Pedido adicionado.
    <img width="350" height="355" alt="image" src="https://github.com/user-attachments/assets/972d0cc7-d9d5-4ad8-a114-c02816bd7db9" />




5. Tela final - Visualização de um Pedido Finalizado.
    <img width="409" height="334" alt="image" src="https://github.com/user-attachments/assets/32f3ce7e-2903-4d2e-a2b5-5024976c741c" />



6. Estrutura de Arquivos

A estrutura de diretórios do projeto final está organizada da seguinte forma:

Barzinho_C-/

├── .qtcreator/

│ └── CMakeLists.txt.user

├── .gitignore

├── Aperitivo.h

├── Barzinho.cpp

├── barzinho.db

├── barzinho.exe

├── Barzinho.h

├── barzinhoterminal.exe

├── Bebidas.h

├── Cliente.cpp

├── Cliente.h

├── CMakeLists.txt

├── CMakeLists.txt.user

├── main.cpp

├── mainterminal.cpp

├── mainwindow.cpp

├── mainwindow.h

├── mainwindow.ui

├── Pedido.cpp

├── Pedido.h

├── Produto.h

├── programa.exe

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


5. Conclusão

O desenvolvimento do projeto "Cinestesia" permitiu a aplicação prática e a solidificação dos conceitos de Estrutura de Dados e Orientação a Objetos. A utilização de herança e polimorfismo mostrou-se fundamental para a criação de um cardápio flexível e extensível, enquanto o gerenciamento explícito de memória com new e delete foi um desafio central que exigiu um design cuidadoso de "propriedade" dos objetos.

Os objetivos definidos na introdução foram alcançados, resultando em um sistema gráfico funcional que implementa as operações CRUD básicas para um bar, oferecendo uma experiência de usuário satisfatória.


7. Instruções de Compilação

Há duas formas de compilar e executar este projeto:

-Via Qtcreator (com inteface gráfica), pelo arquivo "CMakeLists.txt"

-Via Terminal (sem interface gráfica, pelo executável barzinhoterminal.exe
