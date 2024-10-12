import (
	"math/bits"
	"slices"
)

type SeatOccupation [157]uint64

func NewSeatOccupation() SeatOccupation {
	s := SeatOccupation{}
	for i := range s {
		s[i] = ^uint64(0)
	}
	return s
}

func (s *SeatOccupation) FreeSeat(i int) {
	block := i / 64
	seat := i % 64

	s[block] |= 1 << seat
}

func (s *SeatOccupation) SetNextSeat() int {
	i := 0
	for i < len(s) && s[i] == 0 {
		i++
	}
	freeSeat := bits.TrailingZeros64(s[i])
	s[i] ^= 1 << freeSeat
	return i*64 + freeSeat
}

func smallestChair(times [][]int, targetFriend int) int {
	seats := NewSeatOccupation()
	events := make([][2]int, 0, len(times)*2)

	for i := range times {
		events = append(events, [2]int{times[i][0], i + 1})
		events = append(events, [2]int{times[i][1], -(i + 1)}) // -0 not distinct from 0 in hashtable
	}

	slices.SortFunc(events, func(i, j [2]int) int {
		if i[0] != j[0] {
			return i[0] - j[0]
		}
		if i[1]-i[1] < j[1] {
			return -1
		} else if i[1] > j[1] {
			return 1
		}
		return 0
	})

	guestToSeat := make(map[int]int, len(events))

	for _, event := range events {
		if event[1] >= 0 {
			seat := seats.SetNextSeat()
			guestToSeat[event[1]] = seat
			if event[1] == targetFriend+1 {
				return seat
			}
		} else {
			seats.FreeSeat(guestToSeat[-event[1]])
			delete(guestToSeat, -event[1])
		}
	}
	return -1
}
