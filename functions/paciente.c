typedef struct paciente {
    int id;
    char nome[30];
    int cpf;
    int idade;
    int idmed;
    int estado;
}PACIENTE;

void gestaopac(PACIENTE pacientes[]){
    int num;
    printf("Você escolheu gestão de pacientes! Escolha o que deseja fazer\n\n 1 -- CADASTRAR PACIENTE\n 2 -- CONSULTAR ID\n 3 -- ATUALIZAR PACIENTE\n 4 -- EXCLUIR PACIENTE");
    switch (num){
    case 1:
        break;
    default:
        break;
    }
}