#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex01/main';
						my $output;
						my $expected;
						die "ex01/main failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = '5,6,7,8,9,
-20,-19,-18,-17,-16,
100,
0
';

						


						if ($output eq $expected) {
							say 'work/ex01/main good!';
						} else {
							say "!!!! ERROR in work/ex01/main: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					