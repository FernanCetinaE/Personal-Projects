#lang racket
(define (FarCen x) 
        (+ (* (/ 9.0 5.0)  x) 32.0)
)

(define (Cuadratica x) 
        (+ (expt x 2) (* 2 x) 1)
)

(define (Squared x) 
        (expt x 2)
)

(define (Cubed x) 
        (expt x 3)
)

(define (FibonacciIf n)
  (if (or (= n 1) (= n 0))
      1
      (+ (FibonacciIf (- n 1)) (FibonacciIf (- n 2)))
      )
)

(define (FibonacciCond n)
  (cond
    [(or (= n 1) (= n 0)) 1]
    [(+ (FibonacciCond (- n 1)) (FibonacciCond (- n 2)))])
)

(define (Pot x y)
  (if (= y 0)
      1
      (* x (Pot x (- y 1) ) )
   )
)

(FarCen 10)
(Cuadratica 1)
(Squared 5)
(Cubed 5)
(FibonacciIf 5)
(FibonacciCond 5)
(Pot 3 3)
