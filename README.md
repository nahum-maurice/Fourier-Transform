# Fast-Fourier-Transform
In this repository, my goal is to build a library to perform Fourier transform on complex numbers and also on all finite groups (including non-Abelian groups). Some utilities are developed also including a new implementation of vector, complex numbers and also group operations.

## Motivation
Fourier analysis is the term underlying the process by which general functions are being represented or approximated by sums of trigonometric functions. The subject is large enough and embraces a huge spectrum of the mathematical science (specially of applied mathematics). The Fourier transform itself consists in a change of domain (a function goes from being represented in the domain of time or space to be represented in its correspondent spatial or temporal frequency domain). 
The applications of the Fourier transform are enormous and one of the simple cases is what we call lossy compression for audio files. Considering an audio signal, which gives intensity as a function of time, we can Fourier transform it to have its representation in the frequency domain. Then, delete the less importants frequencies (those with small amplitudes and those, which are at a higher range of the spectrum). By doing that, and inverse Fourier transform the signal, we obtain a lighter signal.
In a general way, we can understand the importance of the Fourier Transform in the possibility it gives us to manipulate the building blocks of a functions in another domain and the fact that it always can be reversed.

## Why groups ?
The fundamental principles of Fourier Analysis can be transferred to the case of arbitrary finite groups. The Fourier transform then acts similarly, by converting the function into a new basis with the application of representation theory. Researchers are already using the Fourier transform on groups to perform a huge amount of applications including compression and potential and steady-state temperature problems. Such works have application in different domains such as the PDE world and object-tracking in machine learning. 


## The work here 
In this repository, the idea is to implement the real and the complex Discrete Fourier Transform (for vectors with 2^n samples) and then to extend the implementation to a group-theoretic approach. 
