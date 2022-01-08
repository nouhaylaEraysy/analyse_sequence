#include "../lib/utils.h"
#include "../lib/constants.h"
#include "module_transcription.h"

int main(int argc, char *argv[]) {
    char *filePath;
    char *sequence;
    char  message[60];
    char *rna_sequence = NULL;

    system("setterm -bold on"); // Pour formatage d message en gras

    //generation message to display in the terminator
    sprintf(message, "%sPlease entre a valid codon sequence : %s", BLU, RESET);

    // User request function to upload file
    get_path_from_user(&filePath, message);

    system("setterm -bold off"); // fin fonction de bold

    // retrieving the sequence from the file
    extract_sequence(filePath, &sequence);

    while (valid_sequence(sequence) == 0) {
        printf("%s%s%s", RED, "\nInvalid sequence. Please enter a valid codon sequence: ", RESET);
        get_path_from_user(&filePath, "");
        extract_sequence(filePath, &sequence);
    }

    char file_rna_name[200];

    // Generation of file name to enter
    sprintf(file_rna_name, RNA_SEQUENCE_FILE, timeInMilliseconds());

    // RNA generation (replacing all ’T’ by ’U’)
    rna_sequence = replaceWord(sequence, NEC_T, NEC_U);

    // Record RNA sequence
    int is_saved = save_sequence(rna_sequence, file_rna_name, MAX_LINE_LENGTH);

    // Display of the message if the file is correctly saved
    if (is_saved == 1) {
        printf("%sFile is saved in %s %s", GRN, file_rna_name, RESET);
    } else {
        printf("%sERROR: file is not saved in %s %s", RED, file_rna_name, RESET);
    }
    return 0;
}