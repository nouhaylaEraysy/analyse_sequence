#include "../lib/utils.h"
#include "../lib/constants.h"
#include "recherche_sequence.h"

int main(int argc, char *argv[]) {
    char *filePath;
    char *dna_sequence;
    char *maxSequence;
    char  message[60];

    sprintf(message, "%sPlease entre a valid DNA sequence : %s", BLU, RESET);
    get_path_from_user(&filePath, message);
    extract_sequence(filePath, &dna_sequence);

    // validation sequence DNA
    while (valid_dna_sequence(dna_sequence) == 0) {
        printf("%s\nInvalid DNA sequence. Please enter a valid DNA sequence:%s ", RED, RESET);
        get_path_from_user(&filePath, "");
        extract_sequence(filePath, &dna_sequence);
    }
    // Remove all space and return a line
    removeAllSpaceAndReturnAline(&dna_sequence);

    //get max sequence codon
    getAllCodonSequencesFromDNA(dna_sequence, &maxSequence);

    // check if sequence max existes
    if (strlen(maxSequence) > 0) {
        // generate file name max sequence
        char filename_max_sequence[200];
        sprintf(filename_max_sequence, MAX_CONDON_SEQUENCE_FILE, timeInMilliseconds());

        // save a file
        int is_saved = save_sequence(maxSequence, filename_max_sequence, MAX_LINE_LENGTH);
        if (is_saved == 1) {
            printf("%sfile is saved in %s %s", GRN, filename_max_sequence, RESET);
        }
    }


    return 1;
}