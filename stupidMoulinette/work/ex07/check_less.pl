#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex07/main_less';
						my $output;
						my $expected;
						die "ex07/main_less failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "\n\n";

						


						if ($output eq $expected) {
							say 'work/ex07/main_less good!';
						} else {
							say "!!!! ERROR in work/ex07/main_less: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					