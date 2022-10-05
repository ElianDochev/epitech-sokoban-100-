/*
** EPITECH PROJECT, 2022
** HEADER FILE
** File description:
** Header file for utilities
*/

#ifndef UTIL_H
    #define UTIL_H

    #include <stdlib.h>

    #define EXIT_ERR_EPI 84
    #define ABS(x) (x < 0 ? -x : x)
//functions like prin_f
void my_printf(char *args, ...);
//selfexcpanatory
int my_compute_power_rec(int nb, int p);
/*cacls the square_root of a unsigned float
(precision is the number of digits after the decimal)*/
float get_square_root(float nb, int precision);
//selfexcpanatory
int my_strlen(char const *str);
//converts a string into an int
int str_to_int(const char *str);
//returns an error msg
void error (char *str);
//converts an int to string (signed)
char *int_to_str(int scr);
//converts an int to string (unsigned)
char *int_to_str_unsigned(unsigned int scr);
//converst letters to uppercase
char *str_upcase(char *str);
//reverses a string with know size
void rev_buff(char *buff, int size);
//copies a string
void copy_str(char *dest, char const *src);
//dublicates a string
char *my_strdup(char const *src);
//compares two strings
int str_cmp(char const *str_one, char const *str_two);
//opens a file and puts its contents into a string
char *open_file(char const *filepath);
//prints a help msg form a path given
void print_help(char *path);
//compares two strings
int str_cmp(char const *str_one, char const *str_two);
//joins two string into one (mallocs)
char *str_join(char const *str_one, char const *str_two);
/*print this when there is an error with the num of args
(last one is for the correct number)*/
void print_bad_args(int ac , char *binary_name, int req_args);
//frees the mem and sets ptr value to null pass it like (void **) &ptr
void xfree(void **ptr);
//converts the string into 2d array of words takes a callback to a dilim func
char **split_str(char *scr, int (*sep)(char));
//returns 1 when the char is endl
int endl_delim(char ch);



/*###########################################################################
######################BEGINING OF HASH TABLE#################################
#############################################################################*/
//inits an empty hash table (all null)
char **init_table_hash(size_t table_size);
//main hash function returns an index from data from 0 to table_size
size_t hash_data(char *str, size_t table_size);
//incerts a str (pointer) in the table
int incert_table_hash(char **table, char *str, size_t table_size);
//looks up if an item is in the hash table(returns null on falier)
char *lookup_table(char **table, char *str, size_t table_size);
//deletes a note from the hash_table (doesnt remove the data)
void hash_note_del(char **table, char *str, size_t table_size);
/*###########################################################################
#######################END OF HASH TABLE#####################################
-----------------------------------------------------------------------------*/



/*###########################################################################
#########################BEGINING OF LIST####################################
#############################################################################*/
//struct for list
typedef struct list {
    char *value;
    struct list *next;
} node_t ;
//incerts a node in the list give the pointer
node_t *list_incert(node_t *list, void *value);
//starts from 0 peeks the node fron the list at the specified index
node_t *peek_index(node_t *list, int index);
//destroys the list but not the eles whitin it
void destroy_list(node_t **list);
/*###########################################################################
#######################END OF LIST###########################################
-----------------------------------------------------------------------------*/

/*###########################################################################
#########################BEGINING OF VECTORS#################################
#############################################################################*/
//int vector
typedef struct {
    int x;
    int y;
} int_vector;
//float vector
typedef struct {
    float x;
    float y;
} float_vector;
//craetes int vector
int_vector create_ivector(int x, int y);
//creates float vector
float_vector create_fvector(float x, float y);
/*###########################################################################
#########################END OF VECTORS######################################
-----------------------------------------------------------------------------*/

#endif