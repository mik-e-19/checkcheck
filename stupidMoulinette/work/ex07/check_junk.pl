#!/usr/bin/env perl
						use strict;
						use warnings;
						use feature 'say';
						
						my $program = './work/ex07/main_junk';
						my $output;
						my $expected;
						die "ex07/main_junk failed to run: $?" if $?;

						


						$output = `$program`;
					
						$expected = "'lol','hi',";

						


						if ($output eq $expected) {
							say 'work/ex07/main_junk good!';
						} else {
							say "!!!! ERROR in work/ex07/main_junk: '$output'";
							say "!!!! EXPECTED: '$expected'" if defined $expected;
						}
					
					