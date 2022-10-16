/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:59:57 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 14:25:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_UTILS_H
#define SPAN_UTILS_H

# include <limits>

typedef unsigned int	span_integral;

typedef enum e_minSpan_opcode {
	MINSPAN_INIT,
	MINSPAN_WORK,
}	t_minSpan_opcode;

template <typename T>
unsigned int	minSpan_map_handler( T& val, t_minSpan_opcode opcode ) {
	static T			prev;
	static unsigned int	cur_best;
	unsigned int		cur_diff;

	if ( MINSPAN_INIT == opcode ) {
		cur_best = std::numeric_limits<unsigned int>::max();
		prev = val;
	}
	else if ( MINSPAN_WORK == opcode )
	{
		//*	we can now apply the concept of "Span" to every class
		//*	that implements a -operator
		//*	and a conversion operator to unsigned int !
		cur_diff = span_integral(val - prev);
		if ( cur_diff < cur_best )
			cur_best = cur_diff;
		prev = val;
	}

	return (cur_best);
}

template <typename T>
struct minSpan_map {
	public:
		unsigned int	shortest_span;
		void	operator() ( T& val ) {
			shortest_span = _minSpan_map(val);
		}
	private:
		unsigned int	_minSpan_map( T& val ) {
			return (minSpan_map_handler( val, MINSPAN_WORK ));
		}
};

template <typename T>
unsigned int minSpan( Span& span ) {
	minSpan_map<T>	minSpan_handle;
	Span::iterator	start = span.begin();
	Span::iterator	end = span.end();
	
	minSpan_map_handler(*start, MINSPAN_INIT);
	minSpan_handle = std::for_each(start + 1, end, minSpan_handle);
	return (minSpan_handle.shortest_span);
}

#endif /* SPAN_UTILS_H */