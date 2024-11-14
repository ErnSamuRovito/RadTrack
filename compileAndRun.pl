#!/usr/bin/perl
use strict;
use warnings;

my $nomeApplicativo = $ARGV[0];

if (not defined $nomeApplicativo) {
    die "Errore: Devi specificare il nome dell'applicativo come argomento.\n";
} else {
    print "Compilazione avviata";
}

# Esegui cmake e controlla il risultato
my $cmake_result = system("cmake CMakeLists.txt");
if ($cmake_result != 0) {
    die "Errore: 'cmake' non è riuscito.\n";
}

print "cmake completato\n";

# Esegui make e controlla il risultato
my $make_result = system("make");
if ($make_result != 0) {
    die "Errore: 'make' non è riuscito.\n";
}

print "make completato\n";

print "$nomeApplicativo avviato\n";

# Esegui l'applicativo compilato e controlla il risultato
my $run_result = system("./$nomeApplicativo");

if ($run_result != 0) {
    die "Errore: Esecuzione dell'applicativo fallita.\n";
}
