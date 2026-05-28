*This project has been created as part of the 42 curriculum by gcelesti.*

<div align="center">

# 📚 Libft

**Recriando a biblioteca padrão do C — do zero.**

![Progress](https://img.shields.io/badge/status-em%20progresso-yellow)
![Norminette](https://img.shields.io/badge/norminette-passing-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)

</div>

---

## Description

**libft** é o primeiro projeto do currículo da 42. O objetivo é reimplementar funções da libc e criar funções utilitárias próprias em C puro — sem usar as funções originais, sem variáveis globais, compilando com `-Wall -Wextra -Werror`.

O resultado final é uma biblioteca estática `libft.a` que será reutilizada em todos os projetos futuros da escola.

> Implementar essas funções do zero é a melhor forma de realmente entender como elas funcionam por dentro.

---

## 🚧 Progresso

> Última atualização: Maio 2026

### Part 1 — Funções da libc

#### Classificação de caracteres
| Função | Status |
|---|---|
| `ft_isalpha` | ✅ Concluído |
| `ft_isdigit` | ✅ Concluído |
| `ft_isalnum` | ✅ Concluído |
| `ft_isascii` | ✅ Concluído |
| `ft_isprint` | ✅ Concluído |

#### Conversão
| Função | Status |
|---|---|
| `ft_toupper` | ✅ Concluído |
| `ft_tolower` | ✅ Concluído |

#### Strings
| Função | Status |
|---|---|
| `ft_strlen` | ✅ Concluído |
| `ft_strchr` | ✅ Concluído |
| `ft_strrchr` | ✅ Concluído |
| `ft_strncmp` | ✅ Concluído |
| `ft_strnstr` | ✅ Concluído |
| `ft_strlcpy` | ✅ Concluído |
| `ft_strlcat` | ✅ Concluído |

#### Memória
| Função | Status |
|---|---|
| `ft_memset` | ✅ Concluído |
| `ft_bzero` | ✅ Concluído |
| `ft_memcpy` | ✅ Concluído |
| `ft_memmove` | ✅ Concluído |
| `ft_memchr` | ✅ Concluído |
| `ft_memcmp` | ✅ Concluído |

#### Conversão numérica e alocação
| Função | Status |
|---|---|
| `ft_atoi` | 🔄 Em progresso |
| `ft_calloc` | 🔄 Em progresso |
| `ft_strdup` | 🔄 Em progresso |

---

### Part 2 — Funções adicionais

| Função | Status |
|---|---|
| `ft_substr` | ⏳ Pendente |
| `ft_strjoin` | ⏳ Pendente |
| `ft_strtrim` | ⏳ Pendente |
| `ft_split` | ⏳ Pendente |
| `ft_itoa` | ⏳ Pendente |
| `ft_strmapi` | ⏳ Pendente |
| `ft_striteri` | ⏳ Pendente |
| `ft_putchar_fd` | ⏳ Pendente |
| `ft_putstr_fd` | ⏳ Pendente |
| `ft_putendl_fd` | ⏳ Pendente |
| `ft_putnbr_fd` | ⏳ Pendente |

---

### Part 3 — Listas encadeadas

| Função | Status |
|---|---|
| `ft_lstnew` | ⏳ Pendente |
| `ft_lstadd_front` | ⏳ Pendente |
| `ft_lstadd_back` | ⏳ Pendente |
| `ft_lstsize` | ⏳ Pendente |
| `ft_lstlast` | ⏳ Pendente |
| `ft_lstdelone` | ⏳ Pendente |
| `ft_lstclear` | ⏳ Pendente |
| `ft_lstiter` | ⏳ Pendente |
| `ft_lstmap` | ⏳ Pendente |

---

**Legenda:** ✅ Concluído · 🔄 Em progresso · ⏳ Pendente

---

## Instructions

### Compilação

```bash
# Compilar a biblioteca
make

# Compilar com bônus (listas encadeadas)
make bonus

# Limpar objetos
make clean

# Limpar tudo
make fclean

# Recompilar do zero
make re
```

### Usar em outro projeto

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o programa
```

### Testar funções específicas da BSD (glibc)

Algumas funções como `ft_strlcpy`, `ft_strlcat` e `ft_bzero` não estão disponíveis por padrão no glibc. Para comparar com a implementação original:

```bash
cc -Wall -Wextra -Werror main.c -lbsd -o test
```

---

## Library — Descrição das funções

### Part 1 · Libc

#### Classificação de caracteres
Todas retornam `1` se o caractere pertence à classe testada, `0` caso contrário.

| Função | Descrição |
|---|---|
| `ft_isalpha(int c)` | Verifica se é uma letra (a-z, A-Z) |
| `ft_isdigit(int c)` | Verifica se é um dígito (0-9) |
| `ft_isalnum(int c)` | Verifica se é letra ou dígito |
| `ft_isascii(int c)` | Verifica se está na tabela ASCII (0–127) |
| `ft_isprint(int c)` | Verifica se é um caractere imprimível |

#### Conversão de caracteres

| Função | Descrição |
|---|---|
| `ft_toupper(int c)` | Converte minúscula para maiúscula |
| `ft_tolower(int c)` | Converte maiúscula para minúscula |

#### Manipulação de strings

| Função | Protótipo | Descrição |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Retorna o comprimento da string |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Primeira ocorrência de `c` em `s` |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Última ocorrência de `c` em `s` |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compara até `n` bytes de duas strings |
| `ft_strnstr` | `char *ft_strnstr(const char *h, const char *n, size_t len)` | Encontra needle em haystack dentro de `len` bytes |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Cópia segura com garantia de NUL-termination |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Concatenação segura com garantia de NUL-termination |

#### Memória

| Função | Protótipo | Descrição |
|---|---|---|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Preenche `n` bytes com o valor `c` |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Zera `n` bytes |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Copia `n` bytes (sem sobreposição) |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t n)` | Copia `n` bytes (com sobreposição segura) |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Procura byte `c` nos primeiros `n` bytes |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compara `n` bytes de duas regiões de memória |

#### Conversão e alocação

| Função | Protótipo | Descrição |
|---|---|---|
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converte string para inteiro |
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Aloca e zera memória |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Duplica uma string em memória alocada |

---

### Part 2 · Funções adicionais

| Função | Protótipo | Descrição |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Extrai substring de `s` a partir de `start` com até `len` chars |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Concatena `s1` e `s2` em nova string alocada |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Remove chars de `set` do início e fim de `s1` |
| `ft_split` | `char **ft_split(char const *s, char c)` | Divide `s` pelo delimitador `c`, retorna array NULL-terminado |
| `ft_itoa` | `char *ft_itoa(int n)` | Converte inteiro para string (inclui negativos) |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Aplica `f` a cada char, retorna nova string |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Aplica `f` in-place a cada char de `s` |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Escreve `c` no file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Escreve string `s` no fd |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Escreve `s` + newline no fd |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Escreve inteiro `n` no fd |

---

### Part 3 · Listas encadeadas

Estrutura `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Função | Protótipo | Descrição |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Cria novo nó com `content` |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Insere `new` no início da lista |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Insere `new` no final da lista |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Conta o número de nós |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Retorna o último nó |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Libera um nó (sem liberar o próximo) |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Libera toda a lista e seta o ponteiro para NULL |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Aplica `f` ao conteúdo de cada nó |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Cria nova lista aplicando `f` a cada nó |

---

## Resources

### Documentação
- [man7.org — Linux man pages](https://man7.org/linux/man-pages/) — referência principal para o comportamento de cada função
- [cppreference.com — C standard library](https://en.cppreference.com/w/c) — referência adicional para protótipos e descrições

### Artigos e tutoriais
- [Linked Lists in C — GeeksForGeeks](https://www.geeksforgeeks.org/linked-list-in-c/) — base para a Part 3
- [Understanding strlcpy and strlcat](https://www.sudo.ws/todd/papers/strlcpy.html) — artigo original dos autores das funções BSD

### Uso de IA
Claude (Anthropic) foi utilizado para: revisão de bugs lógicos nas implementações de `ft_strnstr` e `ft_strlcat` (identificação de índices errados e falta de incremento de variáveis), e geração deste README.
As implementações das funções foram escritas manualmente.

---

<div align="center">
<sub>42 School · gcelesti · 2026</sub>
</div>
