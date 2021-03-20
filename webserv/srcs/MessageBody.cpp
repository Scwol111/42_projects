/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MessageBody.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:47:02 by jsandsla          #+#    #+#             */
/*   Updated: 2021/03/07 13:26:07 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MessageBody.hpp"

std::ostream	&operator<<(std::ostream &output, const MessageBody &body) {
	output << std::string((const char *)body.data(), body.size());
	return output;
}
