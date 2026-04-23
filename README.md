# Array Dinâmico em C
Estrutura de dados que funciona como um vetor, mas que pode aumentar ou diminuir de tamanho em tempo de execução. O array normal, tem seu tamanho definido no momento em que é criado, ele nunca muda, já sua versão dinâmica permite que a memória seja alocada conforme a quantidade de elementos inseridos ou removidos. 
## Detalhamento:
Porque usar **size_t** ? -> "size_t serve para representar tamanhos em bytes de objetos" [StakOverflow](https://pt.stackoverflow.com/questions/59369/quando-usar-size-t). É um tipo de dado
>size_t é o tipo correto para guardar o número de bytes que qualquer coisa (qualquer “objeto”) ocupa na memória do seu programa.

Por que usar capacidade e contagem separadamente?
A capacidade representa o tamanho total da "caixa" que reservamos na memória, enquanto a contagem representa quantos itens reais já colocamos lá dentro. Separar esses dois valores é o segredo do array dinâmico: se aumentássemos o tamanho da memória de 1 em 1 a cada novo item, o programa ficaria extremamente lento. Tendo uma capacidade reserva, só precisamos pedir mais memória quando a "caixa" enche.

A Inicialização {0}
Quando declaramos Array xs = {0};, estamos garantindo que todos os membros da struct comecem "zerados".
Isso é fundamental porque a capacidade e a contagem começam valendo 0, e o ponteiro *item começa apontando para "lugar nenhum" (NULL). A função realloc é inteligente: se passamos um ponteiro NULL para ela na primeira vez, ela entende que deve se comportar como um malloc (criar a memória do zero).

A Mágica do realloc e a Estratégia de Crescimento
No código, quando a contagem atinge a capacidade, precisamos expandir.
A função realloc (Re-Allocate) tenta aumentar o bloco de memória atual. Se não houver espaço físico logo à frente na memória RAM, o realloc encontra um novo espaço maior, copia todos os seus dados para lá de forma invisível, e devolve o novo endereço.

    Por que multiplicar por 2? Começamos com espaço para 256 itens. Quando enche, dobramos para 512, depois 1024, 2048... Dobrar o tamanho faz com que as chamadas ao realloc aconteçam cada vez com menos frequência à medida que o array cresce. Na Ciência da Computação, isso é chamado de Amortização, e garante que o seu código continue rápido mesmo lidando com milhões de dados.

O uso de Macro (#define push_array)
Em vez de criar uma função tradicional, criamos uma Macro. O compilador do C substitui o texto push_array(xs, x) por todo aquele bloco de código antes mesmo de compilar.

    O truque do do { ... } while(0): Pode parecer estranho fazer um loop que roda apenas uma vez, mas isso é um padrão (idioma) clássico em C. Isso agrupa as várias linhas da macro em um único bloco seguro, garantindo que você possa usar o push_array dentro de condicionais if/else sem usar chaves {} e sem quebrar a sintaxe do seu programa.
