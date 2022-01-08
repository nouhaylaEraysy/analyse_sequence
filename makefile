CC=gcc
CFLAGS=-Wall

build_all: transcription_build recherche_build translation_build scoresimilaire calculescore

transcription:
	 ./transcription

recherche:
	 ./recherche

translation:
	 ./translation

transcription_build: module_transcription.o
	$(CC)  module_transcription.o -o transcription

recherche_build: recherche_sequence.o
	$(CC)  recherche_sequence.o -o recherche

translation_build: translation.o
	$(CC)  translation.o -o translation

scoresimilaire: score_similaire.o
	$(CC)  score_similaire.o -o scoresimilaire

calculescore: calcule_score.o
	$(CC)  calcule_score.o -o calculescore

module_transcription.o: module_transcription/module_transcription.c  module_transcription/module_transcription.h
	gcc $(CFLAGS) -c module_transcription/module_transcription.c module_transcription/module_transcription.h

recherche_sequence.o: recherche_sequence/recherche_sequence.c  recherche_sequence/recherche_sequence.h
	gcc $(CFLAGS) -c recherche_sequence/recherche_sequence.c recherche_sequence/recherche_sequence.h

translation.o: traduction/translation.c  traduction/translation.h traduction/proteins.h
	gcc $(CFLAGS) -c traduction/translation.c traduction/translation.h

score_similaire.o: score_similaire/score_similaire.c  score_similaire/score_similaire.h
	gcc $(CFLAGS) -c score_similaire/score_similaire.c score_similaire/score_similaire.h

calcule_score.o: calcule_score/calcule_score.c
	gcc $(CFLAGS) -c calcule_score/calcule_score.c

clean:
	rm -f *.o

mrproper: clean
	rm -f module_transciption transcription score_s recherche calculescore scoresimilaire