#lang racket

(define (len lista)
  (if (null? lista) 0 (+ 1 (len (cdr lista)))
      )
)

(define (search lista elemento)
  (cond
    [(null? lista) #f]
    [(list? (car lista)) (search (car lista) elemento)] ;buscar elemento dentro de listas, dentro de una lista padre
    ;[(and (list? (car lista)) (list? elemento)) (equal? (sort (car lista) <) (sort elemento <))]
    ;[(and (list? (car lista)) (list? elemento)) (eqv? (list->set (car lista)) (list->set elemento))]; busca listas pero hay repeticion
    [(eq? (car lista) elemento) #t]
    [else ( search (cdr lista) elemento)])
)

(search '(2 4 6 8 #f '(1 2 3)) 0)