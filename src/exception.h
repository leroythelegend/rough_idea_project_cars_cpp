#ifndef PCARS_EXCEPTION_H_
#define PCARS_EXCEPTION_H_

#include <exception>
#include <string>

using std::string;

namespace pcars {

	/// \class PCars_Exception
	/// \brief Exception

	class PCars_Exception: public std::exception {
	public:
		using Line = int;
		using File = const char *;
		using Error = int;
		using Message = std::string;
		using Compare = const unsigned int; 
		using To = const unsigned int; 

		/// \brief Constructor
		///
		///		Exception
		///
		/// \param line of exception
		/// \param file of exception
		/// \param error
		/// \return nothing
		/// \throw nothing

		PCars_Exception(const Line, File, const Error) noexcept;

		/// \brief Constructor
		///
		///		Exception
		///
		/// \param line of exception
		/// \param file of exception
		/// \param error
		/// \param message
		/// \return nothing
		/// \throw nothing

		PCars_Exception(const Line, File, const Error, const Message) noexcept;

		/// \brief Constructor
		///
		///		Exception
		///
		/// \param line of exception
		/// \param file of exception
		/// \param message
		/// \return nothing
		/// \throw nothing

		PCars_Exception(const Line, File, const Message) noexcept;

		/// \brief Constructor
		///
		///		Exception
		///
		/// \param line of exception
		/// \param file of exception
		/// \param compare
		/// \param to
		/// \return nothing
		/// \throw nothing

		PCars_Exception(const Line, File, Compare, To) noexcept;

		/// Destructor
		virtual ~PCars_Exception() noexcept;

		/// \brief What Exception
		///
		///		Return Exception
		///
		/// \return exception message
		/// \throw nothing

		virtual const char* what() const noexcept;

	private:
		Line line_;
		std::string file_;
		Error error_;
		Message message_;
		std::string exceptionmessage_;
	};

}

#endif

