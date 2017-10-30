(defvar a)
(defvar b)
(defvar c)
(defvar d)

(write-line "Enter a:")

(setf a (read))

(write-line "Enter b:")

(setf b (read))





(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (+ a b))
	(print"Addition is:")
	(print c)
)))



(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf d (- a b))
	(print"Subtraction is:")
	(print d)
)))



(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (/ a b ))
	(print"Division is:")
	(print c)
)))

(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (* a b ))
	(print"Multiplication is:")
	(print c)
)))

(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (min a b))
	(print"Minimum is:")
	(print c)
)))


(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (max a b))
	(print"Maximum is:")
	(print c)
)))

(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (* a a ))
	(print"Square is:")
	(print c)
)))

(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (sqrt a ))
	(print"Square root is:")
	(print c)
)))



(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (sin a ))
	(print"sine function is:")
	(print c)
)))

(sb-thread:make-thread(lambda()(progn(sleep 0)
	(setf c (cos a ))
	(print"cosine function is:")
	(print c)
)))



(exit)



OUTPUT:


prjlab@prjlab-dx2480-MT:~$ sbcl
This is SBCL 1.1.14.debian, an implementation of ANSI Common Lisp.
More information about SBCL is available at <http://www.sbcl.org/>.

SBCL is free software, provided as is, with absolutely no warranty.
It is mostly in the public domain; some portions are provided under
BSD-style licenses.  See the CREDITS and COPYING files in the
distribution for more information.
* (load "a.lisp")
Enter a:
45
Enter b:
30

"Addition is:" 
75 
"Subtraction is:" 
15 
"Division is:" 
3/2 
"Multiplication is:" 
1350 
"Minimum is:" 
30 
"Maximum is:" 
45 
"Square is:" 
2025 
"Square root is:" 
6.708204 
"sine function is:" 
0.8509035 
"cosine function is:" 
0.52532196 
prjlab@prjlab-dx2480-MT:~$ 

