package main

import (
	"fmt"
	"strings"

	"github.com/google/go-cmp/cmp"
	"github.com/google/go-cmp/cmp/cmpopts"
)

type FareCalculate struct {
	TripID    string
	CreatedAt string
	Base      Base
}

type Base struct {
	FareRef     FareRef
	EntityFares []EntityFare
}

type EntityFare struct {
	Total float64
	Party string
}

type FareRef struct {
	FareFlowID        string
	FareFlowRequestID string
	FareFlowSessionID string
}

func main() {
	structA := FareCalculate{
		TripID:    "T1",
		CreatedAt: "1672979158",
		Base: Base{
			FareRef: FareRef{
				FareFlowID:        "F1",
				FareFlowRequestID: "FR1",
				FareFlowSessionID: "FS1",
			},
			EntityFares: []EntityFare{
				{
					Total: 12.34,
					Party: "org::driver",
				},
				{
					Total: 13.45,
					Party: "org::rider",
				},
			},
		},
	}
	structB := FareCalculate{
		TripID:    "T1",
		CreatedAt: "1672979161",
		Base: Base{
			FareRef: FareRef{
				FareFlowID:        "F1",
				FareFlowRequestID: "FR1",
				FareFlowSessionID: "FS1",
			},
			EntityFares: []EntityFare{
				{
					Total: 12.34,
					Party: "org::driver",
				},
				{
					Total: 13.49,
					Party: "org::rider",
				},
			},
		},
	}

	cmpopts.IgnoreFields()
	diff := cmp.Diff(structA, structB)
	fmt.Println(diff)
}

// DiffReporter is a simple custom reporter that only records differences
// detected during comparison.
type DiffReporter struct {
	path  cmp.Path
	diffs []string
}

func (r *DiffReporter) PushStep(ps cmp.PathStep) {
	r.path = append(r.path, ps)
}

func (r *DiffReporter) Report(rs cmp.Result) {
	if !rs.Equal() {
		vx, vy := r.path.Last().Values()
		r.diffs = append(r.diffs, fmt.Sprintf("%#v:\n\t-: %+v\n\t+: %+v\n", r.path, vx, vy))
	}
}

func (r *DiffReporter) PopStep() {
	r.path = r.path[:len(r.path)-1]
}

func (r *DiffReporter) String() string {
	return strings.Join(r.diffs, "\n")
}
