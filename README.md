# Padroes-de-Projeto-ES
Atividade de Implementação de Padrões de Projeto da disciplina Engenharia de Software

## Utilizei a LLM:
*OpenAI. ChatGPT (modelo GPT-5.5). Assistente de inteligência artificial utilizado como apoio para explicações conceituais e revisão de implementação em C++. Acesso em: 11 jun. 2026.*

### *Link:* https://chatgpt.com/share/6a2b6f71-8654-83e9-98c0-a2bc136e7fb9
---

## *Implementação* : 
Realizei a implementação dos 3 padrões pensando na classe "Condominio" de um sistema prediário, onde é evidente que os dados legais do condominio para qual essa aplicação é feita são absolutos **(Singleton)**; implementei classes como se fossem partes do prédio e utilizei o **(Facade)** para utilização mais simples delas; e ainda utilizei o **(Observer)** como forma de notificar a entrega de encomendas para cada apartamento especifico.

### **Todos no mesmo arquivo:** Implementacao.cpp

## Padrão de Criação : **Singleton**

O padrão Singleton resolve o problema de quando se necessita ter apenas uma instância, alem de protejer de sobrescrita e permitir aceso o universal dela. Ele é utilizado quando temos algo que é constante no nosso código e que não tem sentido em varios objetos desta mesma classe, como um banco de dados.


### *a explicação do código esta na propria implementação* 

---


## Padrão de Estrutura : **Facade**

O padrão Facede facilita a interação com um conjunto grande de classes fornecendo uma interface mais simples. Utilizei ela para gerenciar setores do predio como portaria, garagem e seguranca.

### *a explicação do código esta na propria implementação* 

---

## Padrão de Comportamental : **Observer**
O padrão Observer permite que objetos sejam notificados, utilizei ele como forma de entregar notificações de novas encomendas ao moradores.

### *a explicação do código esta na propria implementação* 

---
