Autores: 
Luiz Daniel Marinho dos Santos - 21953119
Rebeca Pacheco Correa - 21953259
# aed2_biblioteca

## Instrução de Uso

### Compilando o Código:

Primeiro, navegue até o diretório onde os arquivos de código (`gerencia.c`, `livro.c`, `estrutura.c`) estão localizados. Execute o comando abaixo para compilar o código e criar o executável:

```bash
gcc gerencia.c livro.c estrutura.c -o gerencia -Wall
```

Isso criará um arquivo executável chamado `gerencia`.

### Executando o Programa com Testes:

Em seguida, execute o programa usando os arquivos de teste localizados no diretório `../test/`:

```bash
./gerencia ../test/saida.text ../test/ent01.in ../test/ent02.in ../test/ent03.in
```

Esse comando gerará um arquivo de saída (`saida.text`), no qual você poderá verificar os resultados dos testes.
