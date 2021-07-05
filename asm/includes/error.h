/*
** EPITECH PROJECT, 2021
** COREWAR ERROR
** File description:
** error_handler
*/

#ifndef ERROR_HANDLER_H_
#define ERROR_HANDLER_H_

// // Error Macro // //

void exit_error(char *message);

// Basic errors
#define OPEN_ERROR exit_error("Can't open file")
#define ALLOC_ERROR exit_error("Allocation problem")
#define READ_ERROR exit_error("Can't read file")
#define CREATE_ERROR exit_error("Can't create file")
#define MEMORY_ERROR exit_error("Memory allocation failed")

// Args errors
#define UNKNOWN_OPTION_ERROR exit_error("Unknown option. Retry with -h.")
#define NB_ARGS_ERROR exit_error("One argument required.")
#define INVALID_FILE_ERROR exit_error("Invalid file content.")

/* Metadata errors */

#endif /* !ERROR_HANDLER_H_ */
