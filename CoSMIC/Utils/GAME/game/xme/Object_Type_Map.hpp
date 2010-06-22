/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: ace_gperf -t -L C++ -C -g -E Object.gperf  */
#include "Object_Type.h"
#include "ace/OS_NS_string.h"

struct object_type
{
  /// Name of the object type.
  const char * name;

  /// GME object type value.
  int type;
};

class Perfect_Hash
{
private:
  static unsigned int hash (const char *str, unsigned int len);
public:
  static const object_type * in_word_set (const char *str, unsigned int len);
};

inline
unsigned int
Perfect_Hash::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11,  0,
     11,  0, 11,  0,  0, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11,  0,  0,  0,
     11, 11, 11,  0, 11, 11, 11, 11, 11, 11,
     11, 11,  0,  0, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11,
#else
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11,  0, 11,  0,
     11,  0,  0, 11, 11, 11, 11, 11,  0,  0,
      0, 11, 11, 11,  0,  0,  0, 11, 11, 11,
     11, 11, 11, 11, 11, 11, 11, 11,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

inline
const object_type *
Perfect_Hash::in_word_set (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 6,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 10,
      MIN_HASH_VALUE = 3,
      MAX_HASH_VALUE = 10,
      HASH_VALUE_RANGE = 8,
      DUPLICATES = 0,
      WORDLIST_SIZE = 9
    };

  static const struct object_type wordlist[] =
    {
      {"", ::GAME::XME::Object_Type::OT_UNKNOWN},
      {"", ::GAME::XME::Object_Type::OT_UNKNOWN},
      {"", ::GAME::XME::Object_Type::OT_UNKNOWN},
      {"set", ::GAME::XME::Object_Type::OT_SET},
      {"atom", ::GAME::XME::Object_Type::OT_ATOM},
      {"model", ::GAME::XME::Object_Type::OT_MODEL},
      {"folder", ::GAME::XME::Object_Type::OT_FOLDER},
      {"", ::GAME::XME::Object_Type::OT_UNKNOWN},
      {"", ::GAME::XME::Object_Type::OT_UNKNOWN},
      {"reference", ::GAME::XME::Object_Type::OT_REFERENCE},
      {"connection", ::GAME::XME::Object_Type::OT_CONNECTION},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].name;

          if (*str == *s && !ACE_OS::strcmp (str + 1, s + 1))
            return &(wordlist[key]);
        }
    }
  return 0;
}
