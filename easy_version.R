library(tidyverse)

find_letter <- function(word, verbose = FALSE) {
  word_index <- rep(NA, nchar(word))
  for (i in 1:nchar(word)) {
    word_index[i] <- which(letters == substr(word, i, i))
  }
  
  candidates <- 
    expand_grid(
      a = c("-", "*", "/"),
      b = c("-", "*", "/"),
      c = c("-", "*", "/")
    ) %>%
    filter(a != b,
           a != c,
           b != c) %>%
    mutate(expr = paste("((", word_index[1], a, word_index[2], ")", b, 
                        word_index[3], ")", c, word_index[4])) %>%
    rowwise() %>%
    mutate(res  = eval(parse(text = expr))) %>%
    ungroup() %>%
    filter(res == (res - (res %% 1)),
           res > 0,
           res < 27) %>%
    arrange(res)
  
  if (verbose) {
    return(candidates)
  } else {
    return(candidates %>%
             `[`(1, ) %>% 
             pull(res)
           %>%
             {`[`(letters, .)}
    )
  }
}

find_letter("maid", verbose = TRUE)

c("pigs", "sand", "mail", "date", "head", 
  "clam", "peak", "heat", "joya", "well",
  "toad", "card", "will", "tape", "legs", 
  "tree", "road", "maid", "slab", "rock",
  "hand", "vase", "safe", "clay", "toes") %>%
  vapply(X = .,
         FUN = find_letter,
         FUN.VALUE = character(1)) %>%
  paste(collapse = " ")

