#include "IDLStream.h"
#include <ctype.h>

NL::NL (void)
{
}

INDENT::INDENT (int do_now)
  :  do_now_ (do_now)
{
}

UNINDENT::UNINDENT (int do_now)
  :  do_now_ (do_now)
{
}

const NL nl;
const INDENT idt;
const INDENT idt_nl (1);
const UNINDENT uidt;
const UNINDENT uidt_nl (1);

IDLStream::IDLStream (std::ostream& strm)
  : strm_ (strm),
    indent_level_ (0)
{
}

IDLStream::~IDLStream (void)
{

}

void IDLStream::incr_indent (unsigned short flag)
{
  ++ indent_level_;

  if (flag != 0)
  {
    this->indent ();
  }
}

// Indentation
void IDLStream::decr_indent (unsigned short flag)
{
  if (this->indent_level_ > 0)
  {
    -- this->indent_level_;
  }

  if (flag != 0)
  {
    this->indent ();
  }
}

void IDLStream::reset (void)
{
  this->indent_level_ = 0;
}

//
// indent
//
void IDLStream::indent (void)
{
  // Based on the current indentation level, leave appropriate number of blank
  // spaces in the output.
  if (this->indent_level_ > 0)
    {
      for (int i = 0; i < this->indent_level_; i ++)
        {
          this->strm_ << "  ";
        }
    }
}

void IDLStream::nl (void)
{
  // Insert a new line and return to the proper location.
  this->strm_ << std::endl;
  indent ();
}

// Macro generation.
void IDLStream::gen_ifdef_macro (const std::string &name)
{
  this->gen_ifdef_macro (name.c_str ());
}

void IDLStream::gen_ifdef_macro (const char *name)
{
  this->strm_ << "#ifndef ";
  upcase (name);
  this->strm_ << "_CIDL" << std::endl;
  this->strm_ << "#define ";
  upcase (name);
  this->strm_ << "_CIDL" << std::endl
              << std::endl;
}

void IDLStream::gen_endif (const std::string &name)
{
  this->gen_endif (name.c_str ());
}

void IDLStream::gen_endif (const char *name)
{
  this->strm_ << "#endif // !defined ";
  upcase (name);
  this->strm_ << "_CIDL" << std::endl;
}

void IDLStream::gen_cidlc_composition (std::string &component_name)
{
	this->strm_ << "composition session ";
	this->strm_ << component_name;
	this->strm_ << "_Impl";
	this->nl ();

	// Open the brace
	this->strm_ << "{";
	this->nl ();
}

void IDLStream::gen_cidlc_home_decl (std::string &component_name)
{
	this->strm_ << "home executor ";
	this->strm_ << component_name;
	this->strm_ << "Home";
	this->strm_ << "_Exec\n";
	this->indent ();
	this->strm_ << "{";
	this->nl ();
}

void IDLStream::gen_cidlc_implements_decl (std::string &component_name)
{
	this->strm_ << "implements ";
	this->strm_ << component_name;
	this->strm_ << ";";
	this->nl ();
}

void IDLStream::gen_cidlc_manages_decl (std::string &component_name)
{
	this->strm_ << "manages ";
	this->strm_ << component_name;
	this->strm_ << "_Exec;";
	this->nl ();
}

void IDLStream::gen_cidlc_include (std::string &file_name)
{
	this->strm_ 
    << "#include \"" << file_name << ".idl" << "\"" << std::endl;
}

IDLStream & IDLStream::operator << (const std::string &s)
{
  for ( std::string::const_iterator iter = s.begin ();
        iter != s.end ();
        iter ++)
  {
    (*this) << *iter;
  }
  return *this;
}

IDLStream & IDLStream::operator << (const char *str)
{
  while (*str != '\0')
  {
    (*this) << *str ++;
  }
  return *this;
}

IDLStream & IDLStream::operator << (const long &l)
{
  this->strm_ << l;
  return *this;
}

IDLStream & IDLStream::operator << (const unsigned long &ul)
{
  this->strm_ << ul;
  return *this;
}

IDLStream & IDLStream::operator << (const double &d)
{
  this->strm_ << d;
  return *this;
}

IDLStream & IDLStream::operator << (const char &c)
{
  switch (c)
  {
  case '\n':
    nl ();
    break;

  case '\t':
    // Increment the indentation.
    incr_indent ();
    break;

  case '{':
    // Increment the indentation accordingly.
    nl ();
    this->strm_ << '{';
    incr_indent (0);
    nl ();
    break;

  case '}':
    this->strm_ << std::endl;
    decr_indent ();
    this->strm_ << "}";
    break;

  default:
    // Insert the character into the stream.
    this->strm_ << c;
  };

  return *this;
}

void IDLStream::upcase (const char *str)
{
  while (*str != '\0')
  {
    this->strm_ << static_cast<char> (toupper (*str ++));
  }
}

void IDLStream::gen_cidlc_scope (std::stack <std::string> & scope)
{

}
