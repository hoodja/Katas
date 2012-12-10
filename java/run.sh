#!/bin/bash

export CP=/Users/hoodja/.ivy2/cache/junit/junit/jars/*:./
javac -d . -classpath $CP PrimeFactorsTest.java  && java -classpath $CP org.junit.runner.JUnitCore primefactors.PrimeFactorsTest
