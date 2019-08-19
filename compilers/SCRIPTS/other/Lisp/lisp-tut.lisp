(setq *print-case* :capitalize)

(format t "(+ 5 4) = ~d ~%" (+ 5 4))
(format t "(- 5 4) = ~d ~%" (- 5 4))
(format t "(* 5 4) = ~d ~%" (* 5 4))
(format t "(/ 5 4) = ~d ~%" (/ 5 4))
(format t "(/ 5 4.0) = ~d ~%" (/ 5 4.0))
(format t "(rem 5 4) = ~d ~%" (rem 5 4))
(format t "(mod 5 4) = ~d ~%" (mod 5 4))



(defparameter *name* 'Derek)
(format t "(eq *name 'Derek) = ~d ~%" (eq *name* 'Derek))

