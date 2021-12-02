#pragma once
#include <ostream>

#define MAX_COORD 10000000 // MAX_COORD: Η μέγιστη δινατή διάσταση του πίνακα.

struct Coordinates
// Ζεύγος συντεταγμένων γραμμή/στήλη για τον προσδιορισμό του κελιού του αραιού πίνακα.
{
    unsigned int row; // γραμμή, zero-based (η αρίθμηση ξεκινάει από το μηδέν).
    unsigned int col; // στήλη, zero-based (η αρίθμηση ξεκινάει από το μηδέν).

    bool operator<(const Coordinates& right) const
    // Τελεστής ταξινόμησης.
    // Κατατάσσει κατά απόλυτη σειρά τα στοιχεία ενός πίνακα με μοναδικό τρόπο.
    // Hint: χρειάζεται για την εισαγωγή ενός στοιχείου τύπου Coordinates σε
    // δομή με ταξινομημένα στοιχεία.
    // Οι γραμμές (row) έχουν προτεραιότητα ως προς τις στήλες:
    // ένα ζεύγος (row,col) = (0,κ) είναι πάντα μικρότερο από το (1,λ),
    // για κάθε κ,λ < MAX_COORD.
    {
        return row * MAX_COORD + col < right.row * MAX_COORD + right.col;
    }
};

template <typename T>
class SparseMatrixTraits
// Το public interface που πρέπει (κατ ελάχιστον) να έχει η SparseMatrix.
// H SparseMatrix πρέπει να κληρονομεί την SparseMatrixTraits.
// To template argument T είναι ο τύπος δεδομένου που αποθηκεύουμε στον
// αραιό πίνακα.
{
public:
    virtual const T& operator()(Coordinates pos) const = 0;
    // επιστρέφει const αναφορά στο στοιχείο του πίνακα στη θέση pos.
    // Αν δεν υπάρχει προσδιορισμένο στοιχείο σε αυτή τη θέση, επιστρέφει
    // αναφορά στο default στοιχείο (βλ. παρακάτω ελεύθερη συνάρτηση getNullElement).

    virtual T& operator()(Coordinates pos) = 0;
    // επιστρέφει αναφορά στο στοιχείο του πίνακα στη θέση pos.
    // Αν δεν υπάρχει προσδιορισμένο στοιχείο σε αυτή τη θέση, κατασκευάζει και εισάγει ένα
    // νέο (με default τιμή) σε αυτή τη θέση και επιστρέφει αναφορά σε αυτό.

    SparseMatrixTraits() {}
    // Default constructor.

    virtual void clear() = 0;
    // Μηδενισμός του πίνακα.

    virtual ~SparseMatrixTraits(){};
    // Καταστροφέας

    virtual void print() = 0;
    // Εκτυπώνει τα προσδιορισμένα στοιχεία του πίνακα, ένα στοιχείο ανά γραμμή,
    // ταξινομημένα πρώτα κατά γραμμή και μετά κατά στήλη (σύμφωνα με τον κανόνα διάταξης
    // που ορίζει ο τελεστής < της struct Coordinates).
    // H μορφοποιημένη έξοδος της μεθόδου για κάθε γραμμή πρέπει να έχει τη μορφή:
    // (row, col): value
    // π.χ.:
    // (0, 10): -2.2
    // (0, 11): 66.9
    // (100, 22): 100.223

    virtual bool operator==(const SparseMatrixTraits& right) { return true; }
    // Πρέπει να επιστρέφει false αν τουλάχιστο ένα στοιχείο του στιγμιοτύπου δεν υπάρχει στο right
    // ή αν τουλάχιστο ένα στοιχείο του right δεν υπάρχει στο παρόν στιγμιότυπο.
};

template <typename T>
static const T& getNullElement() {
    static const T _null_element = T();
    return _null_element;
}
// Κατασκευάζει στατικά και επιστρέφει αναφορά στο "μηδενικό" στοιχείο του τύπου που
// αποθηκεύουμε στον αραιό πίνακα. Είναι απαραίτητη η χρήση της όταν κατά την υλοποίηση του τελεστή ()
// από την κλάση SparseMatrix<T> πρέπει να επιστρέψουμε αναφορά σε στοιχείο που δεν υπάρχει
// στον αραιό πίνακα.
