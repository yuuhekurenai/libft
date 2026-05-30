#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/* =========================================================== */
/*                        COLORS & UI                          */
/* =========================================================== */
#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define CYAN    "\033[0;36m"
#define YELLOW  "\033[0;33m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define RESET   "\033[0m"

static int	g_pass = 0;
static int	g_fail = 0;
static int	g_skip = 0;

/* =========================================================== */
/*              WEAK STUBS — NOT IMPLEMENTED YET               */
/* =========================================================== */

/* Each stub sets a flag so the test knows to skip */
static int	g_not_impl = 0;

#define STUB_INT(fn)    __attribute__((weak)) int    fn(void)          { g_not_impl = 1; return (0); }
#define STUB_SIZET(fn)  __attribute__((weak)) size_t fn(void)          { g_not_impl = 1; return (0); }
#define STUB_PTR(fn)    __attribute__((weak)) void  *fn(void)          { g_not_impl = 1; return (NULL); }
#define STUB_VOID(fn)   __attribute__((weak)) void   fn(void)          { g_not_impl = 1; }
#define STUB_TLIST(fn)  __attribute__((weak)) t_list *fn(void)         { g_not_impl = 1; return (NULL); }

/* Part 1 */
STUB_INT(ft_isalpha)
STUB_INT(ft_isdigit)
STUB_INT(ft_isalnum)
STUB_INT(ft_isascii)
STUB_INT(ft_isprint)
STUB_INT(ft_toupper)
STUB_INT(ft_tolower)
STUB_INT(ft_atoi)
STUB_SIZET(ft_strlen)
STUB_SIZET(ft_strlcpy)
STUB_SIZET(ft_strlcat)
STUB_PTR(ft_strchr)
STUB_PTR(ft_strrchr)
STUB_PTR(ft_strnstr)
STUB_PTR(ft_memset)
STUB_PTR(ft_bzero)
STUB_PTR(ft_memcpy)
STUB_PTR(ft_memmove)
STUB_PTR(ft_memchr)
STUB_INT(ft_memcmp)
STUB_INT(ft_strncmp)
STUB_PTR(ft_calloc)
STUB_PTR(ft_strdup)

/* Part 2 */
STUB_PTR(ft_substr)
STUB_PTR(ft_strjoin)
STUB_PTR(ft_strtrim)
STUB_PTR(ft_split)
STUB_PTR(ft_itoa)
STUB_PTR(ft_strmapi)
STUB_VOID(ft_striteri)
STUB_VOID(ft_putchar_fd)
STUB_VOID(ft_putstr_fd)
STUB_VOID(ft_putendl_fd)
STUB_VOID(ft_putnbr_fd)

/* Part 3 */
STUB_TLIST(ft_lstnew)
STUB_VOID(ft_lstadd_front)
STUB_INT(ft_lstsize)
STUB_TLIST(ft_lstlast)
STUB_VOID(ft_lstadd_back)
STUB_VOID(ft_lstdelone)
STUB_VOID(ft_lstclear)
STUB_VOID(ft_lstiter)
STUB_TLIST(ft_lstmap)

/* =========================================================== */
/*                     HELPERS & CHECKS                        */
/* =========================================================== */

static void	print_header(const char *name)
{
	g_not_impl = 0;
	printf("\n"BOLD CYAN"  ▶ %s"RESET"\n", name);
}

static void	print_section(const char *name)
{
	printf("\n"BOLD YELLOW
		"╔══════════════════════════════════════╗\n"
		"║  %-36s║\n"
		"╚══════════════════════════════════════╝"
		RESET"\n", name);
}

static void	print_not_impl(const char *fname)
{
	printf(YELLOW"    ⏳ %s — NOT IMPLEMENTED YET\n"RESET, fname);
	g_skip++;
}

static void	check_int(const char *test, int expected, int got)
{
	if (g_not_impl)
		return ;
	if (expected == got)
	{ printf(GREEN"    ✓ "RESET DIM"%s"RESET"\n", test); g_pass++; }
	else
	{ printf(RED"    ✗ "RESET"%s"RED" [expected: %d | got: %d]"RESET"\n", test, expected, got); g_fail++; }
}

static void	check_ptr(const char *test, void *expected, void *got)
{
	if (g_not_impl)
		return ;
	if (expected == got)
	{ printf(GREEN"    ✓ "RESET DIM"%s"RESET"\n", test); g_pass++; }
	else
	{ printf(RED"    ✗ "RESET"%s"RED" [expected: %p | got: %p]"RESET"\n", test, expected, got); g_fail++; }
}

static void	check_str(const char *test, const char *expected, const char *got)
{
	if (g_not_impl)
		return ;
	if (expected == NULL && got == NULL)
	{ printf(GREEN"    ✓ "RESET DIM"%s → both NULL"RESET"\n", test); g_pass++; return ; }
	if (expected && got && strcmp(expected, got) == 0)
	{ printf(GREEN"    ✓ "RESET DIM"%s → \"%s\""RESET"\n", test, got); g_pass++; }
	else
	{ printf(RED"    ✗ "RESET"%s"RED" [expected: \"%s\" | got: \"%s\"]"RESET"\n",
		test, expected ? expected : "NULL", got ? got : "NULL"); g_fail++; }
}

static void	check_size(const char *test, size_t expected, size_t got)
{
	if (g_not_impl)
		return ;
	if (expected == got)
	{ printf(GREEN"    ✓ "RESET DIM"%s → %zu"RESET"\n", test, got); g_pass++; }
	else
	{ printf(RED"    ✗ "RESET"%s"RED" [expected: %zu | got: %zu]"RESET"\n", test, expected, got); g_fail++; }
}

static void	manual_out(const char *label)
{
	if (g_not_impl)
		return ;
	printf(YELLOW"    ~ "RESET"%s → ", label);
	fflush(stdout);
}

/* =========================================================== */
/*                        PART 1                               */
/* =========================================================== */

static void	test_isalpha(void)
{
	print_header("ft_isalpha");
	if (g_not_impl) { print_not_impl("ft_isalpha"); return ; }
	check_int("'a' is alpha",    !!(isalpha('a')),  !!(ft_isalpha('a')));
	check_int("'Z' is alpha",    !!(isalpha('Z')),  !!(ft_isalpha('Z')));
	check_int("'1' not alpha",   !!(isalpha('1')),  !!(ft_isalpha('1')));
	check_int("' ' not alpha",   !!(isalpha(' ')),  !!(ft_isalpha(' ')));
	check_int("'\\0' not alpha", !!(isalpha('\0')), !!(ft_isalpha('\0')));
}

static void	test_isdigit(void)
{
	print_header("ft_isdigit");
	if (g_not_impl) { print_not_impl("ft_isdigit"); return ; }
	check_int("'0' is digit",  !!(isdigit('0')), !!(ft_isdigit('0')));
	check_int("'9' is digit",  !!(isdigit('9')), !!(ft_isdigit('9')));
	check_int("'a' not digit", !!(isdigit('a')), !!(ft_isdigit('a')));
	check_int("'/' not digit", !!(isdigit('/')), !!(ft_isdigit('/')));
}

static void	test_isalnum(void)
{
	print_header("ft_isalnum");
	if (g_not_impl) { print_not_impl("ft_isalnum"); return ; }
	check_int("'a' is alnum",  !!(isalnum('a')), !!(ft_isalnum('a')));
	check_int("'5' is alnum",  !!(isalnum('5')), !!(ft_isalnum('5')));
	check_int("'!' not alnum", !!(isalnum('!')), !!(ft_isalnum('!')));
	check_int("'Z' is alnum",  !!(isalnum('Z')), !!(ft_isalnum('Z')));
}

static void	test_isascii(void)
{
	print_header("ft_isascii");
	if (g_not_impl) { print_not_impl("ft_isascii"); return ; }
	check_int("0 is ascii",    !!(isascii(0)),   !!(ft_isascii(0)));
	check_int("127 is ascii",  !!(isascii(127)), !!(ft_isascii(127)));
	check_int("128 not ascii", !!(isascii(128)), !!(ft_isascii(128)));
	check_int("-1 not ascii",  !!(isascii(-1)),  !!(ft_isascii(-1)));
}

static void	test_isprint(void)
{
	print_header("ft_isprint");
	if (g_not_impl) { print_not_impl("ft_isprint"); return ; }
	check_int("' ' is print",    !!(isprint(' ')),  !!(ft_isprint(' ')));
	check_int("'~' is print",    !!(isprint('~')),  !!(ft_isprint('~')));
	check_int("'\\t' not print", !!(isprint('\t')), !!(ft_isprint('\t')));
	check_int("'\\0' not print", !!(isprint('\0')), !!(ft_isprint('\0')));
	check_int("31 not print",    !!(isprint(31)),   !!(ft_isprint(31)));
}

static void	test_toupper(void)
{
	print_header("ft_toupper");
	if (g_not_impl) { print_not_impl("ft_toupper"); return ; }
	check_int("'a' → 'A'",    toupper('a'), ft_toupper('a'));
	check_int("'z' → 'Z'",    toupper('z'), ft_toupper('z'));
	check_int("'A' unchanged", toupper('A'), ft_toupper('A'));
	check_int("'1' unchanged", toupper('1'), ft_toupper('1'));
}

static void	test_tolower(void)
{
	print_header("ft_tolower");
	if (g_not_impl) { print_not_impl("ft_tolower"); return ; }
	check_int("'A' → 'a'",    tolower('A'), ft_tolower('A'));
	check_int("'Z' → 'z'",    tolower('Z'), ft_tolower('Z'));
	check_int("'a' unchanged", tolower('a'), ft_tolower('a'));
	check_int("'1' unchanged", tolower('1'), ft_tolower('1'));
}

static void	test_strlen(void)
{
	print_header("ft_strlen");
	if (g_not_impl) { print_not_impl("ft_strlen"); return ; }
	check_size("empty string", strlen(""),      ft_strlen(""));
	check_size("\"hello\"",    strlen("hello"), ft_strlen("hello"));
	check_size("single char",  strlen("x"),     ft_strlen("x"));
}

static void	test_strchr(void)
{
	char	s[] = "hello world";

	print_header("ft_strchr");
	if (g_not_impl) { print_not_impl("ft_strchr"); return ; }
	check_ptr("find 'o'",      strchr(s, 'o'),  ft_strchr(s, 'o'));
	check_ptr("find 'h'",      strchr(s, 'h'),  ft_strchr(s, 'h'));
	check_ptr("not found 'z'", strchr(s, 'z'),  ft_strchr(s, 'z'));
	check_ptr("find '\\0'",    strchr(s, '\0'), ft_strchr(s, '\0'));
}

static void	test_strrchr(void)
{
	char	s[] = "hello world";

	print_header("ft_strrchr");
	if (g_not_impl) { print_not_impl("ft_strrchr"); return ; }
	check_ptr("last 'o'",      strrchr(s, 'o'),  ft_strrchr(s, 'o'));
	check_ptr("last 'l'",      strrchr(s, 'l'),  ft_strrchr(s, 'l'));
	check_ptr("not found 'z'", strrchr(s, 'z'),  ft_strrchr(s, 'z'));
	check_ptr("find '\\0'",    strrchr(s, '\0'), ft_strrchr(s, '\0'));
}

static void	test_strncmp(void)
{
	print_header("ft_strncmp");
	if (g_not_impl) { print_not_impl("ft_strncmp"); return ; }
	check_int("equal n=5",
		strncmp("hello", "hello", 5) == 0, ft_strncmp("hello", "hello", 5) == 0);
	check_int("differ at 3rd",
		strncmp("abc", "abd", 3) < 0,      ft_strncmp("abc", "abd", 3) < 0);
	check_int("n=0 always equal",
		strncmp("abc", "xyz", 0) == 0,     ft_strncmp("abc", "xyz", 0) == 0);
	check_int("prefix shorter s1",
		strncmp("ab", "abc", 3) < 0,       ft_strncmp("ab", "abc", 3) < 0);
}

static void	test_strnstr(void)
{
	print_header("ft_strnstr");
	if (g_not_impl) { print_not_impl("ft_strnstr"); return ; }
	check_ptr("found within len",
		strnstr("hello world", "world", 11), ft_strnstr("hello world", "world", 11));
	check_ptr("len too short",
		strnstr("hello world", "world", 5),  ft_strnstr("hello world", "world", 5));
	check_ptr("empty needle",
		strnstr("hello", "", 5),             ft_strnstr("hello", "", 5));
	check_ptr("needle not found",
		strnstr("hello", "xyz", 5),          ft_strnstr("hello", "xyz", 5));
	check_ptr("len=0 empty needle",
		strnstr("hello", "", 0),             ft_strnstr("hello", "", 0));
}

static void	test_strlcpy(void)
{
	char	dst1[20]; char dst2[20];

	print_header("ft_strlcpy");
	if (g_not_impl) { print_not_impl("ft_strlcpy"); return ; }
	check_size("returns src len",
		strlcpy(dst1, "hello", 20), ft_strlcpy(dst2, "hello", 20));
	check_str("copies correctly", dst1, dst2);
	check_size("size=0",
		strlcpy(dst1, "hello", 0), ft_strlcpy(dst2, "hello", 0));
	check_size("size < src",
		strlcpy(dst1, "hello", 3), ft_strlcpy(dst2, "hello", 3));
	check_str("truncated", dst1, dst2);
}

static void	test_strlcat(void)
{
	char	dst1[20]; char dst2[20];

	print_header("ft_strlcat");
	if (g_not_impl) { print_not_impl("ft_strlcat"); return ; }
	strcpy(dst1, "hello"); strcpy(dst2, "hello");
	check_size("normal concat",
		strlcat(dst1, " world", 20), ft_strlcat(dst2, " world", 20));
	check_str("result", dst1, dst2);
	strcpy(dst1, "hello"); strcpy(dst2, "hello");
	check_size("size < dst len",
		strlcat(dst1, " world", 3), ft_strlcat(dst2, " world", 3));
	strcpy(dst1, "hi"); strcpy(dst2, "hi");
	check_size("size=0",
		strlcat(dst1, "abc", 0), ft_strlcat(dst2, "abc", 0));
}

static void	test_memset(void)
{
	char	b1[10]; char b2[10];

	print_header("ft_memset");
	if (g_not_impl) { print_not_impl("ft_memset"); return ; }
	memset(b1, 'A', 10); ft_memset(b2, 'A', 10);
	check_int("fill 'A'", memcmp(b1, b2, 10) == 0, 1);
	memset(b1, 0, 10);   ft_memset(b2, 0, 10);
	check_int("fill 0",   memcmp(b1, b2, 10) == 0, 1);
	memset(b1, 'Z', 0);  ft_memset(b2, 'Z', 0);
	check_int("n=0",      memcmp(b1, b2, 10) == 0, 1);
}

static void	test_bzero(void)
{
	char	b1[10]; char b2[10];

	print_header("ft_bzero");
	if (g_not_impl) { print_not_impl("ft_bzero"); return ; }
	memset(b1, 'X', 10); memset(b2, 'X', 10);
	bzero(b1, 10);       ft_bzero(b2, 10);
	check_int("zeroes 10 bytes", memcmp(b1, b2, 10) == 0, 1);
	memset(b1, 'X', 10); memset(b2, 'X', 10);
	bzero(b1, 0);        ft_bzero(b2, 0);
	check_int("n=0 no change",   memcmp(b1, b2, 10) == 0, 1);
}

static void	test_memcpy(void)
{
	char	src[] = "hello"; char d1[10]; char d2[10];

	print_header("ft_memcpy");
	if (g_not_impl) { print_not_impl("ft_memcpy"); return ; }
	memcpy(d1, src, 6);   ft_memcpy(d2, src, 6);
	check_int("copy 6 bytes", memcmp(d1, d2, 6) == 0, 1);
	memcpy(d1, src, 0);   ft_memcpy(d2, src, 0);
	check_int("n=0 no copy", memcmp(d1, d2, 6) == 0, 1);
}

static void	test_memmove(void)
{
	char	b1[] = "hello world"; char b2[] = "hello world";
	char	b3[] = "hello world"; char b4[] = "hello world";

	print_header("ft_memmove");
	if (g_not_impl) { print_not_impl("ft_memmove"); return ; }
	memmove(b1 + 3, b1, 5);  ft_memmove(b2 + 3, b2, 5);
	check_int("overlap forward",  memcmp(b1, b2, 11) == 0, 1);
	memmove(b3, b3 + 3, 5);  ft_memmove(b4, b4 + 3, 5);
	check_int("overlap backward", memcmp(b3, b4, 11) == 0, 1);
}

static void	test_memchr(void)
{
	char	s[] = "hello world";

	print_header("ft_memchr");
	if (g_not_impl) { print_not_impl("ft_memchr"); return ; }
	check_ptr("find 'o'",      memchr(s, 'o', 11), ft_memchr(s, 'o', 11));
	check_ptr("not found 'z'", memchr(s, 'z', 11), ft_memchr(s, 'z', 11));
	check_ptr("n=0",           memchr(s, 'h', 0),  ft_memchr(s, 'h', 0));
}

static void	test_memcmp(void)
{
	print_header("ft_memcmp");
	if (g_not_impl) { print_not_impl("ft_memcmp"); return ; }
	check_int("equal",
		memcmp("abc", "abc", 3) == 0, ft_memcmp("abc", "abc", 3) == 0);
	check_int("s1 < s2",
		memcmp("abc", "abd", 3) < 0,  ft_memcmp("abc", "abd", 3) < 0);
	check_int("n=0 equal",
		memcmp("abc", "xyz", 0) == 0, ft_memcmp("abc", "xyz", 0) == 0);
}

static void	test_atoi(void)
{
	print_header("ft_atoi");
	if (g_not_impl) { print_not_impl("ft_atoi"); return ; }
	check_int("\"42\"",      atoi("42"),      ft_atoi("42"));
	check_int("\"-42\"",     atoi("-42"),     ft_atoi("-42"));
	check_int("\"+42\"",     atoi("+42"),     ft_atoi("+42"));
	check_int("\"   42\"",   atoi("   42"),   ft_atoi("   42"));
	check_int("\"0\"",       atoi("0"),       ft_atoi("0"));
	check_int("\"\"",        atoi(""),        ft_atoi(""));
	check_int("\"42abc\"",   atoi("42abc"),   ft_atoi("42abc"));
	check_int("\"abc\"",     atoi("abc"),     ft_atoi("abc"));
	check_int("\"  -0042\"", atoi("  -0042"), ft_atoi("  -0042"));
}

static void	test_calloc(void)
{
	void	*p1; void *p2;

	print_header("ft_calloc");
	if (g_not_impl) { print_not_impl("ft_calloc"); return ; }
	p1 = calloc(5, sizeof(int));
	p2 = ft_calloc(5, sizeof(int));
	check_int("5 ints zeroed", memcmp(p1, p2, 5 * sizeof(int)) == 0, 1);
	free(p1); free(p2);
	p1 = calloc(0, sizeof(int));
	p2 = ft_calloc(0, sizeof(int));
	check_int("nmemb=0 non-NULL freeable", p1 != NULL && p2 != NULL, 1);
	free(p1); free(p2);
}

static void	test_strdup(void)
{
	char	*s1; char *s2;

	print_header("ft_strdup");
	if (g_not_impl) { print_not_impl("ft_strdup"); return ; }
	s1 = strdup("hello"); s2 = ft_strdup("hello");
	check_str("duplicates \"hello\"", s1, s2);
	check_int("different pointers", s1 != s2, 1);
	free(s1); free(s2);
	s1 = strdup(""); s2 = ft_strdup("");
	check_str("empty string", s1, s2);
	free(s1); free(s2);
}

/* =========================================================== */
/*                        PART 2                               */
/* =========================================================== */

static void	test_substr(void)
{
	char	*s;

	print_header("ft_substr");
	if (g_not_impl) { print_not_impl("ft_substr"); return ; }
	s = ft_substr("hello world", 6, 5);
	check_str("\"world\" from index 6", "world", s); free(s);
	s = ft_substr("hello", 0, 3);
	check_str("first 3 chars", "hel", s); free(s);
	s = ft_substr("hello", 10, 5);
	check_str("start beyond string → empty", "", s); free(s);
	s = ft_substr("hello", 1, 0);
	check_str("len=0 → empty", "", s); free(s);
	s = ft_substr("hello", 0, 100);
	check_str("len > string → full copy", "hello", s); free(s);
}

static void	test_strjoin(void)
{
	char	*s;

	print_header("ft_strjoin");
	if (g_not_impl) { print_not_impl("ft_strjoin"); return ; }
	s = ft_strjoin("hello", " world");
	check_str("join two strings", "hello world", s); free(s);
	s = ft_strjoin("", "world");
	check_str("s1 empty", "world", s); free(s);
	s = ft_strjoin("hello", "");
	check_str("s2 empty", "hello", s); free(s);
	s = ft_strjoin("", "");
	check_str("both empty", "", s); free(s);
}

static void	test_strtrim(void)
{
	char	*s;

	print_header("ft_strtrim");
	if (g_not_impl) { print_not_impl("ft_strtrim"); return ; }
	s = ft_strtrim("  hello  ", " ");
	check_str("trim spaces", "hello", s); free(s);
	s = ft_strtrim("xxhelloxx", "x");
	check_str("trim 'x'", "hello", s); free(s);
	s = ft_strtrim("hello", "x");
	check_str("nothing to trim", "hello", s); free(s);
	s = ft_strtrim("   ", " ");
	check_str("all in set → empty", "", s); free(s);
	s = ft_strtrim("", " ");
	check_str("empty string", "", s); free(s);
}

static void	test_split(void)
{
	char	**arr; int i;

	print_header("ft_split");
	if (g_not_impl) { print_not_impl("ft_split"); return ; }
	arr = ft_split("hello world foo", ' ');
	check_str("split[0]", "hello", arr[0]);
	check_str("split[1]", "world", arr[1]);
	check_str("split[2]", "foo",   arr[2]);
	check_ptr("NULL terminated", NULL, arr[3]);
	i = 0; while (arr[i]) free(arr[i++]); free(arr);
	arr = ft_split("", ' ');
	check_ptr("empty → {NULL}", NULL, arr[0]); free(arr);
	arr = ft_split("   ", ' ');
	check_ptr("only delimiters → {NULL}", NULL, arr[0]); free(arr);
	arr = ft_split("one", ' ');
	check_str("single word", "one", arr[0]);
	check_ptr("NULL terminated", NULL, arr[1]);
	free(arr[0]); free(arr);
}

static void	test_itoa(void)
{
	char	*s;

	print_header("ft_itoa");
	if (g_not_impl) { print_not_impl("ft_itoa"); return ; }
	s = ft_itoa(42);          check_str("42",      "42",          s); free(s);
	s = ft_itoa(-42);         check_str("-42",     "-42",         s); free(s);
	s = ft_itoa(0);           check_str("0",       "0",           s); free(s);
	s = ft_itoa(2147483647);  check_str("INT_MAX", "2147483647",  s); free(s);
	s = ft_itoa(-2147483648); check_str("INT_MIN", "-2147483648", s); free(s);
}

static char	toupper_map(unsigned int i, char c) { (void)i; return ((char)toupper(c)); }
static void	apply_upper(unsigned int i, char *c) { (void)i; *c = (char)toupper(*c); }

static void	test_strmapi(void)
{
	char	*s;

	print_header("ft_strmapi");
	if (g_not_impl) { print_not_impl("ft_strmapi"); return ; }
	s = ft_strmapi("hello", toupper_map);
	check_str("all uppercase", "HELLO", s); free(s);
	s = ft_strmapi("", toupper_map);
	check_str("empty string", "", s); free(s);
}

static void	test_striteri(void)
{
	char	s1[] = "hello";

	print_header("ft_striteri");
	if (g_not_impl) { print_not_impl("ft_striteri"); return ; }
	ft_striteri(s1, apply_upper);
	check_str("modifies in place", "HELLO", s1);
}

static void	test_putchar_fd(void)
{
	print_header("ft_putchar_fd");
	if (g_not_impl) { print_not_impl("ft_putchar_fd"); return ; }
	manual_out("ft_putchar_fd('A', 1)");
	ft_putchar_fd('A', 1);
	printf(DIM"  ← expected: A"RESET"\n");
}

static void	test_putstr_fd(void)
{
	print_header("ft_putstr_fd");
	if (g_not_impl) { print_not_impl("ft_putstr_fd"); return ; }
	manual_out("ft_putstr_fd(\"hello\", 1)");
	ft_putstr_fd("hello", 1);
	printf(DIM"  ← expected: hello"RESET"\n");
}

static void	test_putendl_fd(void)
{
	print_header("ft_putendl_fd");
	if (g_not_impl) { print_not_impl("ft_putendl_fd"); return ; }
	manual_out("ft_putendl_fd(\"hello\", 1)");
	ft_putendl_fd("hello", 1);
	printf(DIM"  ← expected: hello + newline above"RESET"\n");
}

static void	test_putnbr_fd(void)
{
	print_header("ft_putnbr_fd");
	if (g_not_impl) { print_not_impl("ft_putnbr_fd"); return ; }
	manual_out("ft_putnbr_fd(42, 1)");
	ft_putnbr_fd(42, 1);
	printf(DIM"  ← expected: 42"RESET"\n");
	manual_out("ft_putnbr_fd(-42, 1)");
	ft_putnbr_fd(-42, 1);
	printf(DIM"  ← expected: -42"RESET"\n");
	manual_out("ft_putnbr_fd(INT_MIN, 1)");
	ft_putnbr_fd(-2147483648, 1);
	printf(DIM"  ← expected: -2147483648"RESET"\n");
}

/* =========================================================== */
/*                        PART 3                               */
/* =========================================================== */

static void	del_node(void *c) { (void)c; }
static void	del_free(void *c) { free(c); }
static void	iter_fn(void *c)  { (void)c; }

static void	*map_upper(void *content)
{
	char	*src; char *dst; size_t i;

	src = (char *)content;
	dst = malloc(strlen(src) + 1);
	if (!dst) return (NULL);
	i = 0;
	while (src[i]) { dst[i] = (char)toupper(src[i]); i++; }
	dst[i] = '\0';
	return (dst);
}

static void	test_lstnew(void)
{
	t_list	*node;

	print_header("ft_lstnew");
	if (g_not_impl) { print_not_impl("ft_lstnew"); return ; }
	node = ft_lstnew("hello");
	check_str("content set",  "hello", node->content);
	check_ptr("next is NULL", NULL, node->next);
	free(node);
	node = ft_lstnew(NULL);
	check_ptr("NULL content", NULL, node->content);
	check_ptr("next is NULL", NULL, node->next);
	free(node);
}

static void	test_lstadd_front(void)
{
	t_list	*lst; t_list *n1; t_list *n2;

	print_header("ft_lstadd_front");
	if (g_not_impl) { print_not_impl("ft_lstadd_front"); return ; }
	n1 = ft_lstnew("first"); n2 = ft_lstnew("second");
	lst = n1;
	ft_lstadd_front(&lst, n2);
	check_str("new head is second", "second", lst->content);
	check_str("next is first",      "first",  lst->next->content);
	free(n1); free(n2);
}

static void	test_lstsize(void)
{
	t_list	*n1; t_list *n2; t_list *n3;

	print_header("ft_lstsize");
	if (g_not_impl) { print_not_impl("ft_lstsize"); return ; }
	check_int("NULL = 0", 0, ft_lstsize(NULL));
	n1 = ft_lstnew("a"); n2 = ft_lstnew("b"); n3 = ft_lstnew("c");
	n1->next = n2; n2->next = n3;
	check_int("3 nodes = 3", 3, ft_lstsize(n1));
	free(n1); free(n2); free(n3);
}

static void	test_lstlast(void)
{
	t_list	*n1; t_list *n2; t_list *n3;

	print_header("ft_lstlast");
	if (g_not_impl) { print_not_impl("ft_lstlast"); return ; }
	check_ptr("NULL returns NULL", NULL, ft_lstlast(NULL));
	n1 = ft_lstnew("a"); n2 = ft_lstnew("b"); n3 = ft_lstnew("c");
	n1->next = n2; n2->next = n3;
	check_ptr("last node is n3", n3,  ft_lstlast(n1));
	check_str("last content",    "c", ft_lstlast(n1)->content);
	free(n1); free(n2); free(n3);
}

static void	test_lstadd_back(void)
{
	t_list	*lst; t_list *n1; t_list *n2;

	print_header("ft_lstadd_back");
	if (g_not_impl) { print_not_impl("ft_lstadd_back"); return ; }
	n1 = ft_lstnew("first"); n2 = ft_lstnew("second");
	lst = n1;
	ft_lstadd_back(&lst, n2);
	check_str("head unchanged", "first",  lst->content);
	check_str("last is second", "second", ft_lstlast(lst)->content);
	free(n1); free(n2);
}

static void	test_lstdelone(void)
{
	t_list	*n1; t_list *n2;

	print_header("ft_lstdelone");
	if (g_not_impl) { print_not_impl("ft_lstdelone"); return ; }
	n1 = ft_lstnew("a"); n2 = ft_lstnew("b");
	n1->next = n2;
	ft_lstdelone(n1, del_node);
	check_str("next node untouched", "b", n2->content);
	free(n2);
}

static void	test_lstclear(void)
{
	t_list	*lst; t_list *n1; t_list *n2; t_list *n3;

	print_header("ft_lstclear");
	if (g_not_impl) { print_not_impl("ft_lstclear"); return ; }
	n1 = ft_lstnew("a"); n2 = ft_lstnew("b"); n3 = ft_lstnew("c");
	n1->next = n2; n2->next = n3; lst = n1;
	ft_lstclear(&lst, del_node);
	check_ptr("pointer set to NULL", NULL, lst);
}

static void	test_lstiter(void)
{
	t_list	*n1; t_list *n2;

	print_header("ft_lstiter");
	if (g_not_impl) { print_not_impl("ft_lstiter"); return ; }
	n1 = ft_lstnew("a"); n2 = ft_lstnew("b");
	n1->next = n2;
	ft_lstiter(n1, iter_fn);
	check_int("ran without crash", 1, 1);
	free(n1); free(n2);
}

static void	test_lstmap(void)
{
	t_list	*lst; t_list *result; t_list *n1; t_list *n2;

	print_header("ft_lstmap");
	if (g_not_impl) { print_not_impl("ft_lstmap"); return ; }
	n1 = ft_lstnew("hello"); n2 = ft_lstnew("world");
	n1->next = n2; lst = n1;
	result = ft_lstmap(lst, map_upper, del_free);
	check_str("map[0] uppercased", "HELLO", result->content);
	check_str("map[1] uppercased", "WORLD", result->next->content);
	check_ptr("map[2] NULL",       NULL,    result->next->next);
	ft_lstclear(&result, del_free);
	free(n1); free(n2);
}

/* =========================================================== */
/*                     VALGRIND LAUNCHER                       */
/* =========================================================== */

static void	launch_valgrind(int argc, char **argv)
{
	char	*vg_args[16];
	int		i;

	vg_args[0] = "valgrind";
	vg_args[1] = "--leak-check=full";
	vg_args[2] = "--show-leak-kinds=all";
	vg_args[3] = "--track-origins=yes";
	vg_args[4] = "--error-exitcode=1";
	vg_args[5] = "--log-file=/tmp/vg_libft.log";
	vg_args[6] = "--";
	i = 0;
	while (i < argc && i < 8)
	{ vg_args[7 + i] = argv[i]; i++; }
	vg_args[7 + i] = NULL;
	execvp("valgrind", vg_args);
}

static void	print_valgrind_report(void)
{
	FILE	*f; char line[256]; int leaks;

	printf("\n"BOLD CYAN
		"╔══════════════════════════════════════╗\n"
		"║         VALGRIND  REPORT             ║\n"
		"╚══════════════════════════════════════╝"
		RESET"\n");
	f = fopen("/tmp/vg_libft.log", "r");
	if (!f)
	{ printf(YELLOW"  valgrind log not found\n"RESET); return ; }
	leaks = 0;
	while (fgets(line, sizeof(line), f))
	{
		if (strstr(line, "ERROR SUMMARY") || strstr(line, "LEAK SUMMARY")
			|| strstr(line, "definitely lost") || strstr(line, "indirectly lost")
			|| strstr(line, "possibly lost") || strstr(line, "still reachable")
			|| strstr(line, "All heap blocks were freed"))
		{
			if (strstr(line, "definitely lost") || strstr(line, "indirectly lost"))
				leaks = 1;
			printf(DIM"  %s"RESET, line);
		}
	}
	fclose(f);
	if (!leaks)
		printf(GREEN"\n  ✓ No memory leaks detected!\n"RESET);
	else
		printf(RED"\n  ✗ Memory leaks detected! Check /tmp/vg_libft.log\n"RESET);
}

/* =========================================================== */
/*                          MAIN                               */
/* =========================================================== */

int	main(int argc, char **argv)
{
	int	no_valgrind;

	no_valgrind = (argc > 1 && strcmp(argv[1], "--no-valgrind") == 0);
	if (!no_valgrind && getenv("VALGRIND_RUNNING") == NULL)
	{
		printf(CYAN BOLD"\n  Launching with valgrind...\n"RESET);
		setenv("VALGRIND_RUNNING", "1", 1);
		launch_valgrind(argc, argv);
		printf(YELLOW"  valgrind not found — running without it.\n"RESET);
	}

	printf("\n"BOLD CYAN
		"╔══════════════════════════════════════╗\n"
		"║           LIBFT  TESTS               ║\n"
		"╚══════════════════════════════════════╝"
		RESET"\n");

	print_section("PART 1 — Libc functions");
	test_isalpha(); test_isdigit(); test_isalnum();
	test_isascii(); test_isprint();
	test_toupper(); test_tolower();
	test_strlen();  test_strchr();  test_strrchr();
	test_strncmp(); test_strnstr();
	test_strlcpy(); test_strlcat();
	test_memset();  test_bzero();
	test_memcpy();  test_memmove();
	test_memchr();  test_memcmp();
	test_atoi();    test_calloc();  test_strdup();

	print_section("PART 2 — Additional functions");
	test_substr();  test_strjoin(); test_strtrim();
	test_split();   test_itoa();
	test_strmapi(); test_striteri();
	test_putchar_fd(); test_putstr_fd();
	test_putendl_fd(); test_putnbr_fd();

	print_section("PART 3 — Linked list");
	test_lstnew();      test_lstadd_front();
	test_lstsize();     test_lstlast();
	test_lstadd_back(); test_lstdelone();
	test_lstclear();    test_lstiter();
	test_lstmap();

	printf("\n"BOLD
		"  ┌──────────────────────────────────────┐\n"
		"  │  "GREEN"✓ PASS: %-4d"RESET BOLD
		"  "RED"✗ FAIL: %-4d"RESET BOLD
		"  "YELLOW"⏳ SKIP: %-4d"RESET BOLD"  │\n"
		"  └──────────────────────────────────────┘\n"
		RESET, g_pass, g_fail, g_skip);

	if (getenv("VALGRIND_RUNNING"))
		print_valgrind_report();

	printf("\n");
	return (g_fail > 0 ? 1 : 0);
}
