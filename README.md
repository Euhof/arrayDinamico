# Array Dinâmico em C
Estrutura de dados que funciona como um vetor, mas que pode aumentar ou diminuir de tamanho em tempo de execução. O array normal, tem seu tamanho definido no momento em que é criado, ele nunca muda, já sua versão dinâmica permite que a memória seja alocada conforme a quantidade de elementos inseridos ou removidos. 
## Detalhamento:
Porque usar **size_t** ? -> "size_t serve para representar tamanhos em bytes de objetos" [StakOverflow](https://pt.stackoverflow.com/questions/59369/quando-usar-size-t). É um tipo de dado
>size_t é o tipo correto para guardar o número de bytes que qualquer coisa (qualquer “objeto”) ocupa na memória do seu programa.
