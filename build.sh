echo "Compilando projeto C (compilação recursiva)..."

utilsCFiles=$(find ./utils -type f -name "*.c")

sourceFiles="main.c $utilsCFiles"

echo "Arquivos fonte:"
for f in $sourceFiles; do
    echo "  $f"
done

gcc $sourceFiles -o main

if [ $? -eq 0 ]; then
    echo
    echo "Compilação concuída com sucesso."
    echo
    echo "Executando o programa: "
    ./main
else
    echo
    echo "Erro na compilação..."
fi