/**
 * @brief Header of FileNotFound.
 * @author: Carolina y Maria
 * @since 1.0
 */

#ifndef FILE_NOT_FOUND_H
#define	FILE_NOT_FOUND_H
#include <exception>
using namespace std;
/**
 * File not found exception
 * @brief Show file not found exception
 */
class file_not_found: public exception{
public:
	/**
	 * A exception
	 * Show the exception when the file is not found
	 * @return
	 */
    virtual const char* what() const throw(){
        return "Fichero no encontrado";
    }
    virtual ~file_not_found() throw(){}
};

#endif	/* FILE_NOT_FOUND_H */

